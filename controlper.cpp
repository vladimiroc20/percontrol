/*
DESAROLLADORES: 

IVAN DAVID ACEVEDO MARI�O 		0222020012
RANDY JAVIER GARC�A HERNANDEZ	0221920035
VLADIMIR ORTEGA COHEN 			0222020045
SAMUEL DAVID PEREA SALAZAR 		0222020008
LUIS EDUARDO JULIO PADILLA 		0222020021
ALAN DAVID ESCAMILLA SALAS 		0222020025

*/






#include<iostream>
#include<locale.h>
#include<stdlib.h>
#include<conio.h>


using namespace std;
int main()
{
	system("color B"); //codigo para cambiar el color de la letra 
	setlocale(LC_ALL,"spanish"); 
	int n,opc2,opc3,opc4,codigo_buscado,nd,m,z,b,l; //variables
	int nuevo_codigo; 
	int acum_horas2,acum_horas3,acum_horasz,acum_salario,aux;
	int total_e,s;
	float promedio,cont_bajo;
	int  mi=0,md=0,my=0,nomina=0;
	bool encon=false;
	int mayor_horas=0,menor_horas=999999;
	char opc[1];
	cout<<"�Cuantos trabajadores hacen parte de la empresa?"<<endl; //hallar el valor de n
	cin>>n;
	cout<<"�Cuantos dias demoro la obra?"<<endl; //hallar el valor de m
	cin>>m;
	b=m;
	int codigo[n],horas[n][m],acum_horas[n],salario[n],gua[n]; //declaracion de arreglos y matrices
	float horas_totales[n];
	int valor_horas=5000;
	string nombre[n],nombre_mayor,nombre_menor;

	
	do
	{
	system("cls");
	cout<<"CONTROL HORAS-RELIABLE CONSTRUCTIONS"<<endl;

    cout<<"A. REGISTRAR HORAS TRABAJADAS"<<endl;
    cout<<"B. MODIFICAR DATOS"<<endl;
    cout<<"C. CONSULTAS"<<endl;
    cout<<"D. IMPRIMIR COMPROBANTE DE PAGO"<<endl;
    cout<<"E. SALIR"<<endl;
    cin>>opc[1];
    opc[1]=toupper(opc[1]); // para que reconozca las minusculas
	switch(opc[1])  //switch case para menu principal 
		{
		case 'A': 
				for(int f=0; f<n; f++)  //rellenar los arreglos
				{
					system("cls");
				    do
				    {
				    cout<<"Ingresa el Codigo del trabajador "<<f+1<<" : "<<endl;
					cin>>codigo[f]; //llenando un arreglo 
					
		
					}while (codigo[f-1]==codigo[f]);
			    
				    cout<<"Ingrese el nombre  del trabajador: "<<endl;
				    fflush(stdin); getline(cin, nombre[f]);
				    
                    acum_horas[f]=0;
					nomina=0;  
				for (int c=0; c<m; c++)
				    {
				    do
					{
				    cout<<"Ingrese las horas de trabajo en el dia "<<c+1<<" :"<<endl;
				    cin>>horas[f][c]; 
				    acum_horas[f]+=horas[f][c]; //acumulador de horas
           			salario[f]=acum_horas[f]*valor_horas; //sacar el salario
           			nomina+=salario[f];   //nomina que es la suma de los salarios
				    }while(horas[f][c] > 24); //do while para evitar que  se pongan mas de 24 horas 
                    }
		        }
		        
			system("pause");
			break;    
					
		case 'B':
        system("cls");
             
            cout<<"Ingrese el codigo del miembro a buscar: "<<endl;  
			cin>>codigo_buscado;
            for(int f=0;f<n; f++) //buscar en el arreglo
            {
            if(codigo[f] == codigo_buscado) //condicion para buscar
            {
			cout<<"1.Desea cambiar el nombre"<<endl; 
            cout<<"2.Desea cambiar el numero de horas reportadas"<<endl;
            cin>>opc2; //menu para pedir lo que se quiere cambiar
            if(opc2==1)
            {
            cout<<"Ingrese el nuevo nombre"<<endl;
            cin>>nombre[f]; //remplazar el arreglo
            }
            if(opc2==2)
            {
			cout<<"�En que dia desea cambiar las horas?"<<endl;
			cin>>nd;
			z=nd-1; //como dias lo agregue como f+1, toca restar ya que el usuario no va a digitar dia 0
            cout<<"Ingrese el nuevo numero de horas"<<endl;
            cin>>horas[f][z]; //remplazar la matriz
			}	
            } 
         	}
			 
            system("pause");
			break;
			
		case 'C': 
		
        acum_horasz=0;
	   for(int f=0; f<n; f++)
			{
				for(int c=0; c<b; c++)
				{
				acum_horasz+=horas[f][c];
				if( acum_horasz<promedio)
					{
						cont_bajo++;
					}
			    }
			}
			
	    for(int f=0;f<b;f++)
      	{
		gua[f]=acum_horas[f];
	    }

			system("cls");    
		    cout<<"              CONSULTAS"             <<endl;
            cout<<"1. Consulta de empleado"             <<endl;
            cout<<"2. Reporte y horas de trabajo"       <<endl;
            cout<<"3. Reporte de horas y dias"          <<endl;
            cin>>opc3;
		    if(opc3==1)
		    {
		    cout<<"Ingrese el codigo del empleado: "                         <<endl;
		    cin>>nuevo_codigo;
			for(int f=0; f<n; f++)
			{
			if(nuevo_codigo==codigo[f])
			   	{ 
				 system("cls");
			     cout<<"El empleado esta registrado"                             <<endl;
			     cout<<"\nEl nombre del empleado es: "                <<nombre[f]<<endl;
				    acum_horas[f]=0;
				 	for(int c=0; c<b; c++)
				 	{
				 		cout<<"Horas Trabajadas durante el dia "<<c+1 <<": "<<horas[f][c]<<endl;
				 		acum_horas[f]+=horas[f][c];
				 		
					}
						cout<<"total de horas trabajadas: "<<acum_horas[f]<<endl;
						salario[f]=acum_horas[f]*valor_horas;
						
						cout<<"el salario por el tiempo trabajado es: "<<salario[f]<<endl;
						break;
			    }
				else if(nuevo_codigo != codigo[f])
			    {
			    	system("cls");
			    	cout<<"\n***CODIGO NO REGISTRADO, POR FAVOR INGRESE UN CODIGO VALIDO***"<<endl;
				}
			}
			system("pause");
		    }
		    
			if(opc3==2)
			
			
			{
			for(int f=0;f<n;f++)
           	{
         	for(int c=s+1; c<n;c++)	
	    	{
		     	if(gua[s]<gua[c])
			{
			    aux=gua[s];
		       	gua[s]=gua[c];
			gua[s]=aux;
		   	}
		    }	
            }
            
			for(int f=0;f<n;f++)
				 {
					cout<<"Nombre: "<<nombre[f]<<endl;
					cout<<"Codigo: "<<codigo[f]<<endl;
					cout<<"Horas trabajadas: "<<acum_horas[f]<<endl;
					cout<<"Salario a cancelar: "<<"$"<<salario[f]<<endl;
					cout<<"------------------------------"<<endl;	    
				 }
l=0;
while(gua[0]!= acum_horas[l])
{
	l++;
}
cout<<"el empleado con mas horas es "<<nombre[l]<<endl;
cout<<"Hizo un total de  "<<acum_horas[l]<<" horas "<<endl;
cout<<"Salario: "<<salario[l]<<endl;
l=0;
while(gua[n-1]!=acum_horas[l])
{
	l++;
}
cout<<"el empleado con mas menos horas es "<<nombre[l]<<endl;
cout<<"Hizo un total de  "<<acum_horas[l]<<" horas "<<endl;
cout<<"Salario: "<<salario[l]<<endl;		
cout<<"El Total de la nomina es: "<<nomina<<endl;	
 
 for(int f=0;f<n;f++)
      	{
    	if(salario[f]<499999)
	    {
		mi++;
	    }
	    if(salario[f]>500000 && salario[f]<=1000000)
	    {
		md++;
   	    }
	    if(salario[f]>1000000)
	    {
		my++;
	    }
	    } 
		  
cout<<"porcentaje que gan� menos de $500.000 : "<<(mi*100)/n<<" % "<<endl;
cout<<"El porcentaje que gano entre 500.000 y 1.000.000 : "<<(md*100)/n<<" % "<<endl;
cout<<"El porcentaje que gano m�s de 1.000.000 : "<<(my*100)/n<<" % "<<endl;	
	system("pause");
	break;
			
			}
		
			if(opc3==3)
			{
			acum_horas2=0;
			for(int f=0; f<n; f++)
			{
				for(int c=0; c<b; c++)
				{
					acum_horas2+=horas[c][f];
					nombre[c];
					if(mayor_horas < horas[c][f])
					{
						mayor_horas=horas[c][f];
						nombre_mayor=nombre[c];
					}
					if(menor_horas > horas[c][f])
					{
						menor_horas=horas[c][f];
						nombre_menor=nombre[c];
					}
				}
			cout<<"el empleado con mayor horas trabajadas en el dia # "<<f+1<<" es: "<<nombre_mayor<<endl;
			cout<<"el empleado con menor horas trabajadas en el dia # "<<f+1<<" es: "<<nombre_menor<<endl;	
			cout<<"el mayor numero de horas en el dia # "<<	f+1 <<" : " <<mayor_horas<<endl;
			cout<<"el menor numero de horas en el dia # "<<	f+1 <<" : " <<menor_horas<<endl;
			cout<<"en el dia # "<< f+1 << " se cancela un total de: "	<<salario[f] <<endl;
			system("pause");
			}
			cout<<"el total de horas reportadas en "<<n<<" dias es: "<<acum_horas2<<endl;
			
			promedio=acum_horas2/b;
			cout<<"el promedio fue: "<<promedio<<endl;
			cout<<"el total de dias es: "<<b<<endl;
			cout<<"el numero de dias con un total por debajo del promedio fue: "<<cont_bajo<<endl;
	         }
			system("pause");
			break;
		
		case 'D': 
	    system("cls");
	            
				do{
				system("cls");
				cout<<"COMPROBANTE DE PAGO "	<<endl;
				cout<<"1. Todos los empleados"	<<endl;
				cout<<"2. Un empleado"			<<endl;
				cout<<"3. Para volver al menu principal"<<endl;
				cin>>opc4;
				if(opc4==1)
				{
				cout<<"************************************"<<endl;
				 for(int i=0;i<n;i++)
				 {
					cout<<"Nombre: "<<nombre[i]<<endl;
					cout<<"Codigo: "<<codigo[i]<<endl;
					acum_horas3=0;
					for(int k=0;k<100;k++)
					{
						acum_horas3=acum_horas3+horas[i][k];
					}
					cout<<"Horas trabajadas: "<<acum_horas3<<endl;
					cout<<"Salario a cancelar: "<<"$"<<salario[i]<<endl;
					cout<<"************************************"<<endl;
				 }
				 system("pause");
				}
					if(opc4==2){
					cout<<"ingresar codigo: "<<endl;
					cin>>nuevo_codigo;
					for(int f=0;f<n;f++)
					{
					if(nuevo_codigo==codigo[f])
					{
						encon=true;
						cout<<"************************************"<<endl;
						cout<<"Codigo del Trabajador: "<<codigo[f]<<endl;
						cout<<"Nombre del Trabajador: "<<nombre[f]<<endl;
						acum_horas3=0;
						for(int w=0;w<n;w++)
						{
							acum_horas3=acum_horas3+horas[f][w];
						}
						cout<<"Horas trabajadas: "<<acum_horas3<<endl;
						cout<<"Salario a cancelar: "<<" $"<<salario[f] <<endl;
						cout<<"************************************"<<endl;
						system("pause");
					}
					}
					if(encon==false)
					{
						cout<<"************************************"<<endl;
						cout<<"EL CODIGO '"<<nuevo_codigo<<"' NO HA SIDO ENCONTRADO,"<<endl;
						cout<<"NO EST��REGISTRADO"<<endl;
						cout<<"************************************"<<endl;
						system("pause");
					}
					else
					{
						encon=false;
					}
				}
		        }while (opc4 != 3);
                
		case 'E': exit(0);
    }
	}while (opc!="E");
	
	getch();
	return 0;	
}
