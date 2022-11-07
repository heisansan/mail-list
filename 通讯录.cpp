#include <fstream>
#include <string.h>
#include <iostream>
using namespace std;

class Addre
{
public:
	string shengfen;//省份 
	string chengshi;//城市
	string xianqu;//县区 
	string jiedao;//街道小区详细地址
	string bianma;//邮政编码 
}; 

class Person //定义人类
{
protected:
	char Name[20]; //姓名
	string Tel;  //电话
	string Email;  //email
	string QQ;  //QQ号 
	string WX;  //微信号 
	class Addre Addres;//地址类 
	string Rel; //关系
	int con; 

	Person *next; //Person类对象指针变量
	
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
 
	friend class Manage;//友元类
	/*Manage类是Person类的友元类，则Manage类的所有成员函数都是Person
	类的友元函数，都可以访问Person类的私有和保护成员*/
};
 
class Manage  //管理类
{
public:
	Manage()  //构造函数
	{
		person=0;
		Load();  //成员函数
	}
	~Manage()  //析构函数
	{
		Person *p;//Person类的对象指针变量
		p=person;
		while(p) //当p不为0，即电话簿中记录不为0
		{
			p=p->next;
			delete person; //删除该类对象
			person=p;//准备删除下一对象
		}
		person=0;
	}
 
	void Find(char Name[20]);//按姓名查找
	void Find(string ID); //按特定字符串查找
	void Add(); //添加信息
	void Delete();//删除信息
	void Modify(string NAME);//修改信息
	void Query(); //查询信息
	void Save();//保存数据
	void Load();//读入数据
	void Look();//预览信息
	void DesTory();//清除联系人
	void Exit();//退出界面
	
	void Output(Person *p)
	{
		cout<<"****************************************************"<<endl;
		cout<<"\t姓名: "<<p->Name<<endl;
		cout<<"\t电话: "<<p->Tel<<endl;
		cout<<"\t邮箱: "<<p->Email<<endl;
		cout<<"\tQQ号: "<<p->QQ<<endl;
		cout<<"\t微信号: "<<p->WX<<endl;
		cout<<"\t-----住址-----"<<endl; 
		cout<<"\t省份: "<<p->Addres.shengfen<<endl;
		cout<<"\t城市: "<<p->Addres.chengshi<<endl;
		cout<<"\t县区: "<<p->Addres.xianqu<<endl;
		cout<<"\t街道: "<<p->Addres.jiedao<<endl;
		cout<<"\t邮政编码: "<<p->Addres.bianma<<endl;
		cout<<"\t----------------"<<endl; 
		cout<<"\t关系: "<<p->Rel<<endl;
		cout<<"****************************************************"<<endl;
		cout<<endl;
	}
	
private:
	Person *person; //Person类对象指针
};
void Manage::Add()/*添加联系人*/
{
	system("cls");
	Person *p,*p2; //新节点指针
	string Tel,Email,QQ,WX,shengfen,chengshi,xianqu,jiedao,bianma,Rel;
	char Name[20];
	char c;
	cout<<"\n** 新增通讯录 **\n\n";
	//输入信息

	cout<<"输入姓名:";
	cin>>Name;
	cout<<endl;
	
 	cout<<"输入电话号码:";
	cin>>Tel;
	cout<<endl;
	{//块作用域
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
			cout<<"该联系人电话已存在，\n"<<endl;
			cout<<"该联系人信息为: \n"<<endl;
				Find(Tel);
				cout<<endl;
            cout<<"\n请重新输入(Y/N):"<<endl;
			cin>>c;
			if(toupper(c)=='Y') //toupper()函数是将字符转换为对应的大写字母
			{
				Add();
				return ;
			}
			else
				return ;
		}
	}//块作用域

	cout<<"输入邮箱:";
	cin>>Email;
	cout<<endl;
	
	cout<<"输入QQ:";
	cin>>QQ;
	cout<<endl;
	
	cout<<"输入微信号:";
	cin>>WX;
	cout<<endl;	
	
	cout<<"输入住址:\n";
	cout<<"输入省份:";
	cin>>shengfen;
	cout<<endl;	
	cout<<"输入城市:";
	cin>>chengshi;
	cout<<endl;	
	cout<<"输入县区:";
	cin>>xianqu;
	cout<<endl;	
	cout<<"输入街道小区详细地址:";
	cin>>jiedao;
	cout<<endl;
	cout<<"输入邮政编码:";
	cin>>bianma;
	cout<<endl;
	
	cout<<"输入关系（亲戚/同学/同事/朋友/网友/……）:\n";
	cin>>Rel;
	cout<<endl;	
	
	p=new Person(Name,Tel,Email,QQ,WX,shengfen,chengshi,xianqu,jiedao,bianma,Rel);
	p->next=0;
	//加入链表
   	if(person)  //若已经存在节点
	{
		p2=person;
		while(p2->next) //查找尾节点
		{
			p2=p2->next;
		}
		p2->next=p; //连接
	}
	else //若不存在节点(表空)
	{
		person=p; //连接
	}
	cout<<"\t\t\t ****添加成功***\n"<<endl;
	cout<<"是否继续添加?(Y/N)"<<endl;
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
 
void Manage::Delete()  //删除联系人
{
	system("cls");
	cout<<"\n\t\t** 删除联系人信息 **\n\n";
	cout<<"输入要删除的联系人姓名:\t";
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
			cout<<"\n找到第"<<count<<"个联系人"<<endl;
			p1->con=count;
			Output(p1);	
		}
			p1=p1->next;
	}
	if(count)
	{
		cout<<"\t查询成功!!!\t"<<endl;
		cout<<"\n共找到 "<<count<<" 个联系人"<<endl;
	}
	if(count==0 && p1==NULL)
	{
		cout<<"\t没有找到这个联系人!!!\t"<<endl;
		cout<<"是否继续删除(Y/N): "<<endl;
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
	cout<<"是否仍要删除(Y/N): "<<endl;
	char c; 
	cin>>c;
	if(toupper(c)=='Y')
	{
		cout<<"请问要删除第几个联系人？（1-"<<count<<"）:"<<endl;
		int a;
		cin>>a;
		char b;
		do
		{
			if(p2->Name==NAME && p2->con==a)
			{
				if(p2==person) //若要删除的节点是第一个节点
		 		{
					person=p2->next;
					delete p2;
				}
				else  //若要删除的节点是后续节点
				{
					p3->next=p2->next;
					delete p2;
				}
				cout<<"\n\t\t***删除成功***\n\n";
				cout<<"是否继续删除(Y/N) "<<endl;
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
 
void Manage::Modify(string NAME)/*修改联系人信息*/
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
			cout<<"\n找到第"<<count<<"个联系人"<<endl;
			p1->con=count;
			Output(p1);	
		}
			p1=p1->next;
	}
	if(count)
	{
		cout<<"\t查询成功!!!\t"<<endl;
		cout<<"\n共找到 "<<count<<" 个联系人"<<endl;
	}
	if(count==0 && p1==NULL)
	{
		cout<<"\t没有找到这个联系人!!!\t"<<endl;
		cout<<"是否继续修改(Y/N): "<<endl;
		char c; 
		cin>>c;
			if(toupper(c)=='Y')
			{
				cout<<"请输入要修改人员的姓名"<<endl;
				string NAME; 
				cin>>NAME;
				cout<<endl;
				Modify(NAME);
				return;
			}
			else
				return;
	}
	cout<<"请问要修改第几个联系人？（1-"<<count<<"）:"<<endl;
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
				cout<<"1.修改姓名              2.修改电话          3.修改邮箱 "<<endl;
				cout<<"4.修改QQ号              5.修改微信号        6.修改地址--省份"<<endl;
				cout<<"7.修改地址--城市        8.修改地址--县区    9.修改地址--街道详细地址 "<<endl;
				cout<<"10.修改地址--邮政编码  11.修改关系         12.退出修改"<<endl;
				cout<<"==========================================================================="<<endl;
				cout<<"请选择(1-12)要修改的信息\n";
				cin>>c;
				if(c!=12)
				cout<<"请输入新的信息: ";
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
				cout<<"\n\t   ***修改成功***\n"<<endl;
				cout<<"是否继续修改(Y/N): "<<endl;
				char a;
	            cin>>a;
	            if(toupper(a)=='N')
	            {
					return;
	            }
			}while(c!=12);
			system("cls");
			cout<<"\n\t   ***修改成功***"<<endl;
			cout<<"是否继续修改(Y/N): "<<endl;
			if(toupper(c)=='Y')
			{
				cout<<"请输入要修改人员的姓名"<<endl;
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
 
void Manage::Save()  //保存信息
{
	ofstream fPerson("Person.txt",ios::out);
	char c;
	system("cls");
	cout<<"\n保存数据，是否继续?[Y/N]:";
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
	cout<<"\n保存成功...\n";
	system("pause");
}
 
void Manage::Load()  //数据读入
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
		//员工结点加入链表
		if(person) //若已经存在结点
		{
			Person *p2;
			p2=person;
			while(p2->next) //查找尾结点
			{
				p2=p2->next;
			}
			p2->next=p; //连接
		}
		else //若不存在结点(表空)
		{
			person=p; //连接
		}
		fPerson>>Name>>Tel>>Email>>QQ>>WX>>shengfen>>chengshi>>xianqu>>jiedao>>bianma>>Rel;
	}
	fPerson.close();
}

void Manage::Find(string ID)/*特定字符串：电话、省份查找*/
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
		    cout<<"未找到该联系人!"<<endl;
		}
}

void Manage::Find(char Name[20])/*姓名查找*/
{
	Person *p1;
	int count=0;
	p1=person;
	while(p1)
	{
		if(strcmp(p1->Name,Name)==0)
		{
			count++;
			cout<<"\n找到第"<<count<<"个联系人"<<endl;
			p1->con=count;
			Output(p1);	
		}
			p1=p1->next;
	}
	if(count)
	{
		cout<<"\t查询成功!!!\t"<<endl;
		if(count>1)
		{
			cout<<"\n共找到 "<<count<<" 个联系人"<<endl;
		}
	}
	else
		{cout<<"\n\t\t未找到该联系人!!!\n"<<endl;}
}
 
void Manage::Query()/*/查找的主界面*/
{
	char c;
	string shengfen,Tel;
	char Name[20];
	do{
		cout<<"======================================"<<endl;
		cout<<"1.按电话号码查找  2.按名字查找  3.按省份查找  4.退出查找"<<endl;
		cout<<"请选择查询方法（1-4）:  ";
		cin>>c;
		cout<<endl;
		switch(c)
		{
			case '1':{
				cout<<"输入电话号码:  ";
				cin>>Tel;
				Find(Tel);
					};break;
			case '2':{
				cout<<"输入姓名:  ";
				cin>>Name;
				Find(Name);
					};break;
			case '3':{
				cout<<"输入省份："<<endl;
				cin>>shengfen;
				Find(shengfen);
					};break;	
			case '4':break;
			default: cout<<"输入有误 请重新输入!!!\n"<<endl;
		}
	}while(c!='1'&&c!='2'&&c!='3'&&c!='4');
	cout<<"\t\t\t  ***查找成功***\n"<<endl;
	cout<<"\t是否继续查找（Y/N）?\n";
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
 
void Manage::Look()/*预览信息*/
{
	system("cls");
	Person *p1;
	int count=0;
	char c;
	p1=person;
	while(p1)
	{
		cout<<"\t姓名: "<<p1->Name<<"  电话: "<<p1->Tel<<"  省份: "<<p1->Addres.shengfen<<endl;
		count++;
		p1=p1->next;
	}
	if(count!=0)
	{
		cout<<"\n\t\t预览成功!!!\n"<<endl;
		cout<<"是否继续查询详细信息(Y/N): ";
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
		cout<<"尚未创建通讯录,是否创建(Y/N)"<<endl;
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
 
void Manage::DesTory()/*清除通讯录信息*/
{
	char c;
	system("cls");
	cout<<"\n\t\t\t** 清除信息 **\n";
	cout<<"警告:\n    清除通讯录信息会导致您保存的信息完全消失!!!\n"<<endl;
	cout<<"是否决定清除通讯录信息(Y/N):  "<<endl;
	cin>>c;
	if(toupper(c)!='Y')
		return;
	cout<<"请再次确认(Y/N)"<<endl;
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
 
void Manage::Exit()/*/退出*/
{
    cout<<"\n";
    system("cls");
	puts("\n\t\t感谢使用本系统！！\n\n");
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
	
	do/*菜单操作*/
    {
        system("cls");
        cout<<"\n";
		cout<<"\t\t    ================请选择================"<<endl;
		cout<<"\t\t       ***      1.添加 联系人       ***"<<endl;
		cout<<"\t\t       ***      2.删除 联系人       ***"<<endl;
		cout<<"\t\t       ***      3.修改 联系人       ***"<<endl;
		cout<<"\t\t       ***      4.查询详细信息      ***"<<endl;
		cout<<"\t\t       ***      5.保 存 数 据       ***"<<endl;
		cout<<"\t\t       ***      6.预 览 信 息       ***"<<endl;
		cout<<"\t\t       ***      7.清除 通讯录       ***"<<endl;
		cout<<"\t\t       ***      0.退 出 系 统       ***"<<endl;
		cout<<"\t\t    ======================================"<<endl;
		cout<<"\n\t请选择(0-7): ";
        cin>>c;
        switch(c)
        {
	        case 1: m.Add(); break;
	        case 2: m.Delete();break;
	        case 3: 
			{
			    system("cls");
			    cout<<"==========================================================================="<<endl;
			    cout<<"请输入要修改联系人的姓名:  ";
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
