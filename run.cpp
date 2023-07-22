#include<iostream>
#include<cstdlib>
#include<string.h>
#include<sstream>
#include<unistd.h>

using namespace std;

int main(int argc, char *argv[]){
	if(argc==5){
		char imagen[] = "-i";
		int result_a = strcmp(argv[1], imagen);
		if(result_a==0){
			char file[] = "-f";
			int result_b = strcmp(argv[3], file);
			if(result_b==0){
				string input_password;
				char* password;
				password = getpass("Enter password: ");
				string passwordString(password);
				memset(password, 0, strlen(password));
				stringstream var;
				var<<"zip -P "<<passwordString<<" file.zip "<<argv[4];
				string var_a = var.str();
				system(var_a.c_str());
				stringstream bar;
				bar<<"cat "<<argv[2]<<" file.zip > imagen_resultado.jpg";
				string bar_a = bar.str();
				system(bar_a.c_str());
				system("rm -rf file.zip");
				cout<<"[*] Guardado como imagen_resultado.jpg"<<endl;
			}else{
				char file_a[] = "-path";
				int resiill = strcmp(argv[3], file_a);
				if(resiill==0){
					stringstream har;
					har<<"zip -er file.zip "<<argv[4];
					string har_a = har.str();
					system(har_a.c_str());
					stringstream lar;
					lar<<"cat "<<argv[2]<<" file.zip > imagen_resultado.jpg";
					string lar_a = lar.str();
					system(lar_a.c_str());
					system("rm -rf file.zip");
			}
		}

		}
	}else{
		if(argc==3){
			char extract[]="--extract";
			int log = strcmp(argv[1], extract);
			if(log==0){
				stringstream loco;
				loco<<"unzip "<<argv[2];
				string locoo = loco.str();
				system(locoo.c_str());
				cout<<"[+] Programa extraido correctamente"<<endl;
			}
		}
	}
	return 0;
}