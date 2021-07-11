// evaluasi aritmatika

#include <bits/stdc++.h>

using namespace std;

long unsigned int i;

bool Symbol(char a){
    if(a=='*' || a=='/' || a=='+' ||a=='-' || a=='%'){
        return true; 
    } else {    
        return false; 
    }
}

int parse(char a){ 
    if(a=='+' || a=='-'){ 
        return 1; 
    }
    if(a=='*' || a=='/' || a=='%'){ 
        return 2; 
    } 
    return 0;
}


double applyOpr(double satu, double dua, char opr){
    switch(opr){
        case '*': return satu * dua;    
		case '/': return satu / dua; 
		case '+': return satu + dua; 
		case '-': return satu - dua;
        }
    return 0;
}

for(i=0; i<in.length(); i++){
        if(isdigit(in[i])){
            int nilai=0;
            while(i<in.length() && isdigit(in[i])){
                nilai = (nilai*10) + (in[i] - '0');
                i++;
            }
            i--;
            data.push(nilai);
        }
            else if(in[i] == '(')
                operasi.push(in[i]);
            else if(in[i] == ')'){
                while(!operasi.empty() && operasi.top() != '('){
                    if(operasi.top() == '%'){
                        int kedua = data.top(); data.pop();
                        int pertama  = data.top(); data.pop();
                        operasi.pop();
                        data.push(pertama %kedua);
                        
                    } 
                    else
                         {
                        double kedua = data.top(); data.pop();
                        double pertama  = data.top(); data.pop();
                        char opr = operasi.top(); operasi.pop();
                        data.push(applyOpr(pertama , kedua, opr));
                    }
                }



void hasil(string in){
    stack<double> data;
    stack<char>operasi;
for(i=0; i<in.length(); i++){
        if(isdigit(in[i])){
            int nilai=0;
            while(i<in.length() && isdigit(in[i])){
                nilai = (nilai*10) + (in[i] - '0');
                i++;
            }
            i--;
            data.push(nilai);
        }
            else if(in[i] == '(')
                operasi.push(in[i]);
            else if(in[i] == ')'){
                while(!operasi.empty() && operasi.top() != '('){
                    if(operasi.top() == '%'){
                        int kedua = data.top(); data.pop();
                        int pertama  = data.top(); data.pop();
                        operasi.pop();
                        data.push(pertama %kedua);
                        
                    } 
                    else
                         {
                        double kedua = data.top(); data.pop();
                        double pertama  = data.top(); data.pop();
                        char opr = operasi.top(); operasi.pop();
                        data.push(applyOpr(pertama , kedua, opr));
                    }
                }
                
                if(!operasi.empty())
                    operasi.pop();
                    
            } 
            else 
                {
                if(in[i] == '-'){
                    if(i==0){
                        if(isdigit(in[i+1])){
                            i++;
                            int nilai=0;
                            while(i<in.length() && isdigit(in[i])){
                                nilai = (nilai*10) + (in[i] - '0');
                                i++;
                            }
                            i--;
                            data.push(nilai*-1);
                        } else {
                            data.push(-1);
                            operasi.push('*');
                        }
                        
                    } 
                    else 
                        {
                        while(!operasi.empty() && parse(operasi.top()) >= parse(in[i]) && !Symbol(in[i-1])){
                            if(operasi.top() == '%'){
                                int kedua = data.top(); data.pop();
                                int pertama  = data.top(); data.pop();
                                operasi.pop();
                                data.push(pertama %kedua);
                            
                            } 
                            else 
                                {
                                double kedua = data.top(); data.pop();
                                double pertama  = data.top(); data.pop();
                                char opr = operasi.top(); operasi.pop();
                                data.push(applyOpr(pertama , kedua, opr));
                            }
                        }
                        if((isdigit(in[i+1]) || in[i+1]=='(') && (isdigit(in[i-1]) || in[i-1]==')'))
                            operasi.push(in[i]);
                        
                        else
                            {
                            data.push(-1);
                            operasi.push('*');
                        }
                    } 
                    
                } 
                else 
                    {
                    while(!operasi.empty() && parse(operasi.top()) >= parse(in[i])){
                        if(operasi.top() == '%'){
                            int kedua = data.top(); data.pop();
                            int pertama  = data.top(); data.pop();
                            operasi.pop();
                            data.push(pertama %kedua);
                        } 
                        else 
                            {
                            double kedua = data.top(); data.pop();
                            double pertama  = data.top(); data.pop();
                            char opr = operasi.top(); operasi.pop();
                            data.push(applyOpr(pertama , kedua, opr));
                        }
                    }
                    operasi.push(in[i]);
                }
            }
        }
        
        while(!operasi.empty()){
            if(operasi.top() == '%'){
                int kedua = data.top(); data.pop();
                int pertama  = data.top(); data.pop();
                operasi.pop();
                data.push(pertama %kedua);
         
            } 
            else 
                {
                double kedua = data.top(); data.pop();
                double pertama  = data.top(); data.pop();
                char opr = operasi.top(); operasi.pop();
                data.push(applyOpr(pertama , kedua, opr));
            }
        }
        cout << data.top() << endl;
    }

int main(){
    string ekspresi; getline(cin,ekspresi);
    string baru_ekspresi="";
    for(i=0;i<ekspresi.length();i++){
        if(ekspresi[i]==' ')
            continue;
        else
            baru_ekspresi+=ekspresi[i];
    }
    hasil(baru_ekspresi);

    return 0;
}
