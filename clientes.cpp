#include<iostream>
#include <conio.h>
 //trabajo de sebastian estrada correa y veronica morales orozco//

using namespace std;

   
    void registracliente();
    void mostrar();
    void totaldecredito();

    struct clientes{
    char nombre[100];
    float cupo_credito;
    float cupo_usado;
    clientes *sigiente;
    };

    clientes *cabe, *auxi, *auxi2;

int main(){

    int op=0;

    

    do {
        cout<<"Menu"<<endl<<
        "1. Registrar cliente"<<endl<<
        "2. Mostrar clientes"<<endl<<
        "3. creditos de clientes "<<endl<<
        "4. Salir"<<endl;
        cin>>op;

        switch (op)
        {
        case 1: registracliente(); 
        break;
        case 2: mostrar();
        break;
        case 3: totaldecredito();
        break;        
        }
    } while (op!=4);

    getch();
    return 0;

}


void mostrar(){
    int cont = 1;
    for(auxi=cabe; auxi!=NULL; auxi = auxi->sigiente){

        cout<<"------------------------------"<<endl<<cont++<<". Nombre Paciente: "<<auxi->nombre<<endl<<"credito prestado: "<<auxi->cupo_credito<<endl<<"credito usado: "<<auxi->cupo_usado<<endl;
cout<<"------------------------------"<<endl;
    }
}

void registracliente()
{
     auxi = (struct clientes *) malloc(sizeof(struct clientes));
    auxi->sigiente = NULL;
    cout<<"Registro de cliente"<<endl;
    cout<<"Nombre cliente: ";
    cin>> auxi->nombre;
    cout<<"cuanto credito se le ha asignado: ";
    cin>> auxi->cupo_credito;
    cout<<"cuanto credito a usado: ";
    cin>> auxi->cupo_usado;
    if(!cabe){
        cabe = auxi;
        auxi = NULL;
        free(auxi);
    } else{
        auxi2 = cabe;
        while (auxi2->sigiente != NULL){
            auxi2 = auxi2->sigiente;
        }
        auxi2->sigiente = auxi;
        auxi2 = auxi = NULL;
        free(auxi);
        free(auxi2);
}

}


void totaldecredito()
{
int cont = 1;
for (auxi = cabe; auxi != NULL; auxi = auxi->sigiente)
{
        float total_credito = auxi->cupo_credito - auxi->cupo_usado;
        float porcentaje= (total_credito / auxi->cupo_credito)*100;
        if (porcentaje >= 80)
        {
            cout << "------------------" << endl
                 << cont++ << ". Nombre cliente:" << auxi->nombre << endl
                 << "de su credito prestado:" << auxi->cupo_credito << endl
                 << "el porcentaje de su credito es mayor o igual al 80%: " <<porcentaje << endl;
        }
        else {
     cout<<"------------------"<<endl<<cont++<<". Nombre cliente:"<<auxi->nombre<<endl<<"de su credito prestado:"<<auxi->cupo_credito<<endl<<"el porcentaje de su credito es: "<<porcentaje<<endl;
 }
 if(porcentaje<=20){
     cout<<"------------------"<<endl<<cont++<<". Nombre cliente:"<<auxi->nombre<<endl<<"de su credito prestado:"<<auxi->cupo_credito<<endl<<"el porcentaje de su credito es menor o igual al 20%: "<<porcentaje<<endl;
 }

    }
}