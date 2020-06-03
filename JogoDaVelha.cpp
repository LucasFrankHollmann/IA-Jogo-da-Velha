#include <bits/stdc++.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <limits.h>

using namespace std;

class Tabuleiro
{
    private:
        int matriz[10];
        int luzAlta;
        int eu;
    public:
        
        Tabuleiro(int e)
        {

            for(int i=1;i<10;i++)
                matriz[i]=2;
            luzAlta=1;
			eu=e;
        }
        
        void setLuzAlta(int i)
        {
			luzAlta=i;
		}
        
        int getLuzAlta()
        {
			return luzAlta;
		}
		
        int getSq(int P)
        {
            return matriz[P];
        }
        

        bool Jogue(int V,int P)
        {
            if(getSq(P)==2)
            {
                matriz[P]=V;
                luzAlta++;
                return true;
            }
            else 
            {
                cout<<"Ocupado!"<<endl;
                return false;
            }
            return false;
        }

        void imprime()
        {
            for(int i=1;i<10;i++) 
            {
                if(i%3==1)
                {
                    cout<<endl<<"-------------"<<endl<<"| ";      
                }

                if(matriz[i]==3)
                    cout<<"X | ";
                else if(matriz[i]==5)
                    cout<<"O | ";
                else
                    cout<<"  | ";
            }
            cout<<endl<<"-------------"<<endl;  
            cout<<endl;
        }
        
        void limpa()
        {
            for(int i=1;i<10;i++)
                matriz[i]=2;
        }
        
        int Faz2()
        {
			if(matriz[5]==2)
				return 5;
			else
			{
				if(matriz[2]==2)
					return 2;
				else if(matriz[4]==2)
					return 4;
				else if(matriz[6]==2)
					return 6;
				else if(matriz[8]==2)
					return 8;		
			}
			
			return 0;	
		}
		int Ganha(int p)
		{
			int x=p*p*2;
			//testando as linhas
			for(int i=0;i<3;i++)
			{
				if((matriz[1+(3*i)]*matriz[2+(3*i)]*matriz[3+(3*i)])==x)
				{
					if(matriz[1+(3*i)]==2)
						return (1+(3*i));
					else if(matriz[2+(3*i)]==2)
						return (2+(3*i));	
					else if(matriz[3+(3*i)]==2)
						return (3+(3*i));
				}
		
				if((matriz[1+(i)]*matriz[4+(i)]*matriz[7+(i)])==x)
				{
					if(matriz[1+(i)]==2)
						return (1+(i));
					else if(matriz[4+(i)]==2)
						return (4+(i));	
					else if(matriz[7+(i)]==2)
						return (7+(i));
				}
				
			}	
			
			if((matriz[1]*matriz[5]*matriz[9])==x)
			{
				if(matriz[1]==2)
					return (1);
				else if(matriz[5]==2)						
					return (5);	
				else if(matriz[9]==2)
					return (9);
			}
			
			if((matriz[3]*matriz[5]*matriz[7])==x)
			{
				if(matriz[3]==2)
					return (3);
				else if(matriz[5]==2)						
					return (5);	
				else if(matriz[7]==2)
					return (7);
			}
			return 0;
		}
			
		void Estrategia(int n)
		{
			switch (n){
				
				case 1:
					Jogue(5,1);
					break;
				
				case 2:
					if(getSq(5)==2)
						Jogue(5,5);
					else 
						Jogue(5,1);
					break;
				
				case 3:		
					if(getSq(9)==2)
						Jogue(5,9);
					else 
						Jogue(5,3);
					break;
				
				case 4:
					if(Ganha(3)!=0)
						Jogue(5,Ganha(3));
					else
						Jogue(5,Faz2());
					break;
						
				case 5:
					if(Ganha(3)!=0)
						Jogue(5,Ganha(3));
					else if(Ganha(5)!=0)
						Jogue(5,Ganha(5));
					else if(getSq(7)==0)
						Jogue(5,7);
					else
						Jogue(5,3);
					break;
				
				case 6:
					if(Ganha(5)!=0)
						Jogue(5,Ganha(5));
					else if(Ganha(3)!=0)
						Jogue(5,Ganha(3));
					else 
						Jogue(5,Faz2());
					break;
				
				case 7:
					if(Ganha(5)!=0)
						Jogue(5,Ganha(5));
					else if(Ganha(3)!=0)
						Jogue(5,Ganha(3));
					else
					{
						for(int i=1;i<10;i++)
						{
							if(getSq(i)==2)
							{
								Jogue(5,i);
								break;
							}
						}		
					}	
					break;
					
				case 8:
					if(Ganha(5)!=0)
						Jogue(5,Ganha(5));
					else if(Ganha(3)!=0)
						Jogue(5,Ganha(3));
					else
					{
						for(int i=1;i<10;i++)
						{
							if(getSq(i)==2)
							{
								Jogue(5,i);
								break;
							}
						}		
					}	
					break;
			
				case 9:	
					if(Ganha(5)!=0)
						Jogue(5,Ganha(5));
					else if(Ganha(3)!=0)
						Jogue(5,Ganha(3));
					else
					{
						for(int i=1;i<10;i++)
						{
							if(getSq(i)==2)
							{
								Jogue(5,i);
								break;
							}	
						}		
					}	
					break;
			}	
		}
				
		bool Vitoria()
		{
			int x=27;
			//testando as linhas
			for(int i=0;i<3;i++)
			{
				if((matriz[1+(3*i)]*matriz[2+(3*i)]*matriz[3+(3*i)])==x)
				{
					cout<<"Você ganhou!"<<endl;
					return true;
				}
		
				if((matriz[1+(i)]*matriz[4+(i)]*matriz[7+(i)])==x)
				{
					cout<<"Você ganhou!"<<endl;
					return true;
				}
				
			}	
			
			if((matriz[1]*matriz[5]*matriz[9])==x)
			{
				cout<<"Você ganhou!"<<endl;
				return true;
			}
			
			if((matriz[3]*matriz[5]*matriz[7])==x)
			{
				cout<<"Você ganhou!"<<endl;
				return true;
			}
			
			x=125;
		
			for(int i=0;i<3;i++)
			{
				if((matriz[1+(3*i)]*matriz[2+(3*i)]*matriz[3+(3*i)])==x)
				{
					cout<<"Você perdeu!"<<endl;
					return true;
				}
		
				if((matriz[1+(i)]*matriz[4+(i)]*matriz[7+(i)])==x)
				{
					cout<<"Você perdeu!"<<endl;
					return true;
				}
				
			}	
			
			if((matriz[1]*matriz[5]*matriz[9])==x)
			{
				cout<<"Você perdeu!"<<endl;
				return true;
			}
			
			if((matriz[3]*matriz[5]*matriz[7])==x)
			{
				cout<<"Você perdeu!"<<endl;
				return true;
			}
			return false;
		}	
};


int main()
{
	SetConsoleOutputCP(CP_UTF8);
	Tabuleiro *A=new Tabuleiro(5);
	srand(time(NULL));
	while(1)
	{	
		int jogada;
		A->setLuzAlta(1);
		A->limpa();
		if(rand()%2)
		{
			A->imprime();
			cout<<"Voce comeca. Faca sua jogada"<<endl;
			cin>>jogada;
			while(!A->Jogue(3,jogada))
			{
				cout<<"Valor invalido. Tente novamente!"<<endl;
				cin>>jogada;
			}
			A->imprime();
		}		
		while(!A->Vitoria()&&A->getLuzAlta()<10)
		{
			A->Estrategia(A->getLuzAlta());
			A->imprime();
			
			if(A->Vitoria())
			{	
					break;
			}
			
			else if(A->getLuzAlta()==10)
			{
				break;
			}	
			cout<<"Faca sua jogada"<<endl;
			cin>>jogada;
			while(!A->Jogue(3,jogada))
			{
				cout<<"Valor invalido. Tente novamente!"<<endl;
				cin>>jogada;
			}
			A->imprime();
		}
		
		if(A->getLuzAlta()==10)
			cout<<"Empate!"<<endl;
		
		cout<<"Voce quer jogar novamente (int)?(0 - Nao | 1 - Sim)"<<endl;
		cin>>jogada;
				
		if(!jogada)
			break;
			
    }
    return 0;
}
