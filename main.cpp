#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <vector>
#include <sstream>
#include "Usuario.h"

using namespace std;


int main(){
    stringstream ss;
    char str;
    vector<Usuario> listaUsuario;
    string newNombre, newNombreUsuario, newContrasena, line;
    string linea="";
    float newKm;




    int len =10;
    ifstream archivoUsuarios;
    archivoUsuarios.open("Usuariostt.txt");
    if (archivoUsuarios.fail()) { // Esto es por si no existe el archivo
        cout << "No existe el archivo." << endl;
        exit(1);
    }
    while(getline(archivoUsuarios, line)){
        char arr[line.length() + 1];
        strcpy(arr, line.c_str());
        cout<<arr[0]<<endl;

        if(arr[0]=='U'){
            for (int i=1; i<sizeof(arr); i++){
                linea=linea+arr[i];
            }
            newNombreUsuario=linea;
            linea="";
        }
        if(arr[0]=='C'){
            for (int i=1; i<sizeof(arr); i++){
                linea=linea+arr[i];
            }
            newContrasena=linea;
            linea="";
        }

        if(arr[0]=='N'){
            for (int i=1; i<sizeof(arr); i++){
                linea=linea+arr[i];
            }
            newNombre=linea;
            linea="";
        }

        if(arr[0]=='K'){
            for (int i=1; i<sizeof(arr); i++){
                linea=linea+arr[i];
            }
            newKm=stof(linea);
            Usuario z=Usuario(newNombreUsuario, newContrasena, newNombre, newKm);
            listaUsuario.push_back(z);
            linea="";
        }

    }


    cout<<"Numero de usuarios"<<listaUsuario.size()<<endl;
    cout<<"Usuarios"<<endl;
    for(int i=0; i<listaUsuario.size(); i++){
        cout<<"usuario: "<<listaUsuario[i].getNombreUsuario()<<endl;
        cout<<"contraseña: "<<listaUsuario[i].getContrasena()<<endl;
        cout<<"nombre: "<<listaUsuario[i].getNombre()<<endl;
        cout<<"km acum: "<<listaUsuario[i].getKmAcumulados()<<endl;
    }

    return 0;
}
