#include <fstream>
#include <string.h>
#include <iostream>
using namespace std;

class Addre
{
public:
	string shengfen;//ʡ�� 
	string chengshi;//����
	string xianqu;//���� 
	string jiedao;//�ֵ�С����ϸ��ַ
	string bianma;//�������� 
}; 

class Person //��������
{
protected:
	char Name[20]; //����
	string Tel;  //�绰
	string Email;  //email
	string QQ;  //QQ�� 
	string WX;  //΢�ź� 
	class Addre Addres;//��ַ�� 
	string Rel; //��ϵ
	int con; 

	Person *next; //Person�����ָ�����
	
public:
	Person(char *Name,std::string Tel,std::string Email,std::string QQ,std::string WX,std::string shengfen,std::string chengshi,std::string xianqu,std::string jiedao,std::string bianma,std::string Rel)
	{
		strcpy(this->Name,Name);
		this->Tel=Tel;
		this->Email=Email;
		this->QQ=QQ;
		this->WX=WX;
		this->Addres.shengfen=shengfen;
		this->Addres.chengshi=chengshi;
		this->Addres.xianqu=xianqu;
		this->Addres.jiedao=jiedao;
		this->Addres.bianma=bianma;
		this->Rel=Rel;
		con=0;
	}
 
	friend class Manage;//��Ԫ��
	/*Manage����Person�����Ԫ�࣬��Manage������г�Ա��������Person
	�����Ԫ�����������Է���Person���˽�кͱ�����Ա*/
};
 
class Manage  //������
{
public:
	Manage()  //���캯��
	{
		person=0;
		Load();  //��Ա����
	}
	~Manage()  //��������
	{
		Person *p;//Person��Ķ���ָ�����
		p=person;
		while(p) //��p��Ϊ0�����绰���м�¼��Ϊ0
		{
			p=p->next;
			delete person; //ɾ���������
			person=p;//׼��ɾ����һ����
		}
		person=0;
	}
 
	void Find(char Name[20]);//����������
	void Find(string ID); //���ض��ַ�������
	void Add(); //�����Ϣ
	void Delete();//ɾ����Ϣ
	void Modify(string NAME);//�޸���Ϣ
	void Query(); //��ѯ��Ϣ
	void Save();//��������
	void Load();//��������
	void Look();//Ԥ����Ϣ
	void DesTory();//�����ϵ��
	void Exit();//�˳�����
	
	void Output(Person *p)
	{
		cout<<"****************************************************"<<endl;
		cout<<"\t����: "<<p->Name<<endl;
		cout<<"\t�绰: "<<p->Tel<<endl;
		cout<<"\t����: "<<p->Email<<endl;
		cout<<"\tQQ��: "<<p->QQ<<endl;
		cout<<"\t΢�ź�: "<<p->WX<<endl;
		cout<<"\t-----סַ-----"<<endl; 
		cout<<"\tʡ��: "<<p->Addres.shengfen<<endl;
		cout<<"\t����: "<<p->Addres.chengshi<<endl;
		cout<<"\t����: "<<p->Addres.xianqu<<endl;
		cout<<"\t�ֵ�: "<<p->Addres.jiedao<<endl;
		cout<<"\t��������: "<<p->Addres.bianma<<endl;
		cout<<"\t----------------"<<endl; 
		cout<<"\t��ϵ: "<<p->Rel<<endl;
		cout<<"****************************************************"<<endl;
		cout<<endl;
	}
	
private:
	Person *person; //Person�����ָ��
};
void Manage::Add()/*�����ϵ��*/
{
	system("cls");
	Person *p,*p2; //�½ڵ�ָ��
	string Tel,Email,QQ,WX,shengfen,chengshi,xianqu,jiedao,bianma,Rel;
	char Name[20];
	char c;
	cout<<"\n** ����ͨѶ¼ **\n\n";
	//������Ϣ

	cout<<"��������:";
	cin>>Name;
	cout<<endl;
	
 	cout<<"����绰����:";
	cin>>Tel;
	cout<<endl;
	{//��������
		Person *p1;
		p1=person;
		while(p1)
		{
			if(p1->Tel==Tel)
			{
				break;
			}
			else
			{
				p1=p1->next;
			}
		}
		if(p1!=NULL)
		{
			cout<<"����ϵ�˵绰�Ѵ��ڣ�\n"<<endl;
			cout<<"����ϵ����ϢΪ: \n"<<endl;
				Find(Tel);
				cout<<endl;
            cout<<"\n����������(Y/N):"<<endl;
			cin>>c;
			if(toupper(c)=='Y') //toupper()�����ǽ��ַ�ת��Ϊ��Ӧ�Ĵ�д��ĸ
			{
				Add();
				return ;
			}
			else
				return ;
		}
	}//��������

	cout<<"��������:";
	cin>>Email;
	cout<<endl;
	
	cout<<"����QQ:";
	cin>>QQ;
	cout<<endl;
	
	cout<<"����΢�ź�:";
	cin>>WX;
	cout<<endl;	
	
	cout<<"����סַ:\n";
	cout<<"����ʡ��:";
	cin>>shengfen;
	cout<<endl;	
	cout<<"�������:";
	cin>>chengshi;
	cout<<endl;	
	cout<<"��������:";
	cin>>xianqu;
	cout<<endl;	
	cout<<"����ֵ�С����ϸ��ַ:";
	cin>>jiedao;
	cout<<endl;
	cout<<"������������:";
	cin>>bianma;
	cout<<endl;
	
	cout<<"�����ϵ������/ͬѧ/ͬ��/����/����/������:\n";
	cin>>Rel;
	cout<<endl;	
	
	p=new Person(Name,Tel,Email,QQ,WX,shengfen,chengshi,xianqu,jiedao,bianma,Rel);
	p->next=0;
	//��������
   	if(person)  //���Ѿ����ڽڵ�
	{
		p2=person;
		while(p2->next) //����β�ڵ�
		{
			p2=p2->next;
		}
		p2->next=p; //����
	}
	else //�������ڽڵ�(���)
	{
		person=p; //����
	}
	cout<<"\t\t\t ****��ӳɹ�***\n"<<endl;
	cout<<"�Ƿ�������?(Y/N)"<<endl;
	cin>>c;
	if(toupper(c)=='Y')
	{
		Add();
		return ;
	}
	else
	{ 
		Save();
		return;
	} 
}
 
void Manage::Delete()  //ɾ����ϵ��
{
	system("cls");
	cout<<"\n\t\t** ɾ����ϵ����Ϣ **\n\n";
	cout<<"����Ҫɾ������ϵ������:\t";
	string NAME;
	cin>>NAME;
	cout<<endl;
	Person *p1,*p2,*p3;
	p1=person;
	p2=person;
	p3=person;
	p3=p2;
	int count=0; 
	while(p1!= NULL)
	{
		if(p1->Name==NAME)
		{
			count++;
			cout<<"\n�ҵ���"<<count<<"����ϵ��"<<endl;
			p1->con=count;
			Output(p1);	
		}
			p1=p1->next;
	}
	if(count)
	{
		cout<<"\t��ѯ�ɹ�!!!\t"<<endl;
		cout<<"\n���ҵ� "<<count<<" ����ϵ��"<<endl;
	}
	if(count==0 && p1==NULL)
	{
		cout<<"\tû���ҵ������ϵ��!!!\t"<<endl;
		cout<<"�Ƿ����ɾ��(Y/N): "<<endl;
		char c; 
		cin>>c;
			if(toupper(c)=='Y')
			{
				Delete();
				return;
			}
			else
				return;
	}
	cout<<"�Ƿ���Ҫɾ��(Y/N): "<<endl;
	char c; 
	cin>>c;
	if(toupper(c)=='Y')
	{
		cout<<"����Ҫɾ���ڼ�����ϵ�ˣ���1-"<<count<<"��:"<<endl;
		int a;
		cin>>a;
		char b;
		do
		{
			if(p2->Name==NAME && p2->con==a)
			{
				if(p2==person) //��Ҫɾ���Ľڵ��ǵ�һ���ڵ�
		 		{
					person=p2->next;
					delete p2;
				}
				else  //��Ҫɾ���Ľڵ��Ǻ����ڵ�
				{
					p3->next=p2->next;
					delete p2;
				}
				cout<<"\n\t\t***ɾ���ɹ�***\n\n";
				cout<<"�Ƿ����ɾ��(Y/N) "<<endl;
				cin>>b;
				if(toupper(b)=='Y')
				{
					Delete();
					return ;
				}
			}
			else
			{
				p3=p2;
				p2=p2->next;
			}	
		}while(p2!=NULL);
	}
	else
		return;
}
 
void Manage::Modify(string NAME)/*�޸���ϵ����Ϣ*/
{
	cout<<endl;
	Person *p1,*p2;
	p1=person;
	p2=person;
	int count=0; 
	while(p1!= NULL)
	{
		if(p1->Name==NAME)
		{
			count++;
			cout<<"\n�ҵ���"<<count<<"����ϵ��"<<endl;
			p1->con=count;
			Output(p1);	
		}
			p1=p1->next;
	}
	if(count)
	{
		cout<<"\t��ѯ�ɹ�!!!\t"<<endl;
		cout<<"\n���ҵ� "<<count<<" ����ϵ��"<<endl;
	}
	if(count==0 && p1==NULL)
	{
		cout<<"\tû���ҵ������ϵ��!!!\t"<<endl;
		cout<<"�Ƿ�����޸�(Y/N): "<<endl;
		char c; 
		cin>>c;
			if(toupper(c)=='Y')
			{
				cout<<"������Ҫ�޸���Ա������"<<endl;
				string NAME; 
				cin>>NAME;
				cout<<endl;
				Modify(NAME);
				return;
			}
			else
				return;
	}
	cout<<"����Ҫ�޸ĵڼ�����ϵ�ˣ���1-"<<count<<"��:"<<endl;
	int a;
	cin>>a;
	int c;
	do
	{
		if(p2->Name==NAME && p2->con==a)
		{
			do
			{
				cout<<"==========================================================================="<<endl;
				cout<<"1.�޸�����              2.�޸ĵ绰          3.�޸����� "<<endl;
				cout<<"4.�޸�QQ��              5.�޸�΢�ź�        6.�޸ĵ�ַ--ʡ��"<<endl;
				cout<<"7.�޸ĵ�ַ--����        8.�޸ĵ�ַ--����    9.�޸ĵ�ַ--�ֵ���ϸ��ַ "<<endl;
				cout<<"10.�޸ĵ�ַ--��������  11.�޸Ĺ�ϵ         12.�˳��޸�"<<endl;
				cout<<"==========================================================================="<<endl;
				cout<<"��ѡ��(1-12)Ҫ�޸ĵ���Ϣ\n";
				cin>>c;
				if(c!=12)
				cout<<"�������µ���Ϣ: ";
				switch(c)
				{
					case 1: cin>>p2->Name;break;
					case 2: cin>>p2->Tel;break;
					case 3: cin>>p2->Email;break;
					case 4: cin>>p2->QQ;break;
					case 5: cin>>p2->WX;break;
					case 6: cin>>p2->Addres.shengfen;break;
					case 7: cin>>p2->Addres.chengshi;break;
					case 8: cin>>p2->Addres.xianqu;break;
					case 9: cin>>p2->Addres.jiedao;break;
					case 10: cin>>p2->Addres.bianma;break;
					case 11: cin>>p2->Rel;break;
					default: return; break;
				}
				cout<<"\n\t   ***�޸ĳɹ�***\n"<<endl;
				cout<<"�Ƿ�����޸�(Y/N): "<<endl;
				char a;
	            cin>>a;
	            if(toupper(a)=='N')
	            {
					return;
	            }
			}while(c!=12);
			system("cls");
			cout<<"\n\t   ***�޸ĳɹ�***"<<endl;
			cout<<"�Ƿ�����޸�(Y/N): "<<endl;
			if(toupper(c)=='Y')
			{
				cout<<"������Ҫ�޸���Ա������"<<endl;
				string NAME; 
				cin>>NAME;
				cout<<endl;
				Modify(NAME);
				return;
			}
			else
				return;
		}
		else	
			p2=p2->next;
	}while(p2!=NULL);
}
 
void Manage::Save()  //������Ϣ
{
	ofstream fPerson("Person.txt",ios::out);
	char c;
	system("cls");
	cout<<"\n�������ݣ��Ƿ����?[Y/N]:";
	cin>>c;
	if(toupper(c)!='Y')
		return;
	Person *p=person;
	while(p)
	{
		fPerson<<p->Name<<" "<<p->Tel<<" "<<p->Email<<" "<<p->QQ<<" "<<p->WX<<" "<<p->Addres.shengfen<<" "<<p->Addres.chengshi<<" "<<p->Addres.xianqu<<" "<<p->Addres.jiedao<<" "<<p->Addres.bianma<<" "<<p->Rel<<endl;
		p=p->next;
	}
	fPerson.close();
	cout<<"\n����ɹ�...\n";
	system("pause");
}
 
void Manage::Load()  //���ݶ���
{
	ifstream fPerson;
	Person *p=person;
	string Tel,Email,QQ,WX,shengfen,chengshi,xianqu,jiedao,bianma,Rel;
	char Name[20];
	fPerson.open("person.txt",ios::in);
	fPerson>>Name>>Tel>>Email>>QQ>>WX>>shengfen>>chengshi>>xianqu>>jiedao>>bianma>>Rel;
 
	while(fPerson.good())
	{
		p=new Person(Name,Tel,Email,QQ,WX,shengfen,chengshi,xianqu,jiedao,bianma,Rel);
		p->next=0;
		//Ա������������
		if(person) //���Ѿ����ڽ��
		{
			Person *p2;
			p2=person;
			while(p2->next) //����β���
			{
				p2=p2->next;
			}
			p2->next=p; //����
		}
		else //�������ڽ��(���)
		{
			person=p; //����
		}
		fPerson>>Name>>Tel>>Email>>QQ>>WX>>shengfen>>chengshi>>xianqu>>jiedao>>bianma>>Rel;
	}
	fPerson.close();
}

void Manage::Find(string ID)/*�ض��ַ������绰��ʡ�ݲ���*/
{
	Person *p1;
	p1=person;
	while(p1)
	{
		if(p1->Tel==ID||p1->Addres.shengfen==ID)
			break;
		else
		{
			p1=p1->next;
		}
	}
	if(p1!=NULL)
	{
		Output(p1);
	}
	else
		{
		    cout<<"δ�ҵ�����ϵ��!"<<endl;
		}
}

void Manage::Find(char Name[20])/*��������*/
{
	Person *p1;
	int count=0;
	p1=person;
	while(p1)
	{
		if(strcmp(p1->Name,Name)==0)
		{
			count++;
			cout<<"\n�ҵ���"<<count<<"����ϵ��"<<endl;
			p1->con=count;
			Output(p1);	
		}
			p1=p1->next;
	}
	if(count)
	{
		cout<<"\t��ѯ�ɹ�!!!\t"<<endl;
		if(count>1)
		{
			cout<<"\n���ҵ� "<<count<<" ����ϵ��"<<endl;
		}
	}
	else
		{cout<<"\n\t\tδ�ҵ�����ϵ��!!!\n"<<endl;}
}
 
void Manage::Query()/*/���ҵ�������*/
{
	char c;
	string shengfen,Tel;
	char Name[20];
	do{
		cout<<"======================================"<<endl;
		cout<<"1.���绰�������  2.�����ֲ���  3.��ʡ�ݲ���  4.�˳�����"<<endl;
		cout<<"��ѡ���ѯ������1-4��:  ";
		cin>>c;
		cout<<endl;
		switch(c)
		{
			case '1':{
				cout<<"����绰����:  ";
				cin>>Tel;
				Find(Tel);
					};break;
			case '2':{
				cout<<"��������:  ";
				cin>>Name;
				Find(Name);
					};break;
			case '3':{
				cout<<"����ʡ�ݣ�"<<endl;
				cin>>shengfen;
				Find(shengfen);
					};break;	
			case '4':break;
			default: cout<<"�������� ����������!!!\n"<<endl;
		}
	}while(c!='1'&&c!='2'&&c!='3'&&c!='4');
	cout<<"\t\t\t  ***���ҳɹ�***\n"<<endl;
	cout<<"\t�Ƿ�������ң�Y/N��?\n";
	cin>>c;
	if(toupper(c)=='Y')
		{
		    system("cls");
			Query();
			return ;
		}
	else
		return ;
		system("pause");
}
 
void Manage::Look()/*Ԥ����Ϣ*/
{
	system("cls");
	Person *p1;
	int count=0;
	char c;
	p1=person;
	while(p1)
	{
		cout<<"\t����: "<<p1->Name<<"  �绰: "<<p1->Tel<<"  ʡ��: "<<p1->Addres.shengfen<<endl;
		count++;
		p1=p1->next;
	}
	if(count!=0)
	{
		cout<<"\n\t\tԤ���ɹ�!!!\n"<<endl;
		cout<<"�Ƿ������ѯ��ϸ��Ϣ(Y/N): ";
		cin>>c;
		if(toupper(c)=='Y')
		{
			Query();
			return;
		}
		else
			return;
	}
	else
	{
		cout<<"��δ����ͨѶ¼,�Ƿ񴴽�(Y/N)"<<endl;
		cin>>c;
		if(toupper(c)=='Y')
		{
			Add();
			return;
		}
		else
			return;
	}
}
 
void Manage::DesTory()/*���ͨѶ¼��Ϣ*/
{
	char c;
	system("cls");
	cout<<"\n\t\t\t** �����Ϣ **\n";
	cout<<"����:\n    ���ͨѶ¼��Ϣ�ᵼ�����������Ϣ��ȫ��ʧ!!!\n"<<endl;
	cout<<"�Ƿ�������ͨѶ¼��Ϣ(Y/N):  "<<endl;
	cin>>c;
	if(toupper(c)!='Y')
		return;
	cout<<"���ٴ�ȷ��(Y/N)"<<endl;
	cin>>c;
	if(toupper(c)!='Y')
		return;
	else
	{
		Person *p;
		p=person;
		while(p)
		{
			p=p->next;
			delete person;
			person=p;
		}
		person=0;
	}
	system("pause");
}
 
void Manage::Exit()/*/�˳�*/
{
    cout<<"\n";
    system("cls");
	puts("\n\t\t��лʹ�ñ�ϵͳ����\n\n");
	exit(0);
}

int main(void)
{
	Manage m;
	int c=1;
	int i,k=0;
	string mm;
	string username;
	char mi;
    char a;
	
	do/*�˵�����*/
    {
        system("cls");
        cout<<"\n";
		cout<<"\t\t    ================��ѡ��================"<<endl;
		cout<<"\t\t       ***      1.��� ��ϵ��       ***"<<endl;
		cout<<"\t\t       ***      2.ɾ�� ��ϵ��       ***"<<endl;
		cout<<"\t\t       ***      3.�޸� ��ϵ��       ***"<<endl;
		cout<<"\t\t       ***      4.��ѯ��ϸ��Ϣ      ***"<<endl;
		cout<<"\t\t       ***      5.�� �� �� ��       ***"<<endl;
		cout<<"\t\t       ***      6.Ԥ �� �� Ϣ       ***"<<endl;
		cout<<"\t\t       ***      7.��� ͨѶ¼       ***"<<endl;
		cout<<"\t\t       ***      0.�� �� ϵ ͳ       ***"<<endl;
		cout<<"\t\t    ======================================"<<endl;
		cout<<"\n\t��ѡ��(0-7): ";
        cin>>c;
        switch(c)
        {
	        case 1: m.Add(); break;
	        case 2: m.Delete();break;
	        case 3: 
			{
			    system("cls");
			    cout<<"==========================================================================="<<endl;
			    cout<<"������Ҫ�޸���ϵ�˵�����:  ";
			    string NAME; 
			    cin>>NAME;
			    cout<<endl;
			    m.Modify(NAME);
	        };
				break;
	        case 4: 
			{
	            system("cls");
	            m.Query();
	        }; 
				break;
	        case 5: m.Save(); break;
	        case 6: m.Look(); break;
			case 7: m.DesTory(); break;
	        default:
			{
            	system("cls");
            	m.Save();
           		m.Exit();
			}break;
        }
    }while(c!=0);
	system("cls");
	return 0;
}
