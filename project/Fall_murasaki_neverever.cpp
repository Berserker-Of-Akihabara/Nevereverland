#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>
#include <Windows.h>


int TestOfStringToInt(char testSubj[256],int *resp) //�������� �� �����
{
	int i;
	int res=0;
	*resp=0;
	if(testSubj[0]=='-' && strlen(testSubj)==1)
		return 0;		
	if(testSubj[0]=='-')
		{for(i=1;i<strlen(testSubj);i++)
			if(!isdigit(testSubj[i]))
				return 0;
			else
			res=10*res+(testSubj[i]-'0');
		*resp=res*(-1);
		return -1;}
	else
		{for(i=0;i<strlen(testSubj);i++)
			if(!isdigit(testSubj[i]))
				return 0;
			else
			res=10*res+(testSubj[i]-'0');
		*resp=res;
		return 1;}
}
	
void ReadingIntCheck(int* num,char str[256])	//�������� �� �������� �����
{TestOfStringToInt(str,num);
while (!(*num>0 && *num<501 && TestOfStringToInt(str,num)))
	{printf("�������� ��������.\n");
	scanf("%s",str);
	TestOfStringToInt(str,num);}}
	
int SlDivivder(char wor[500], int place, int* nextsl, int* sllen, int* slcount)
	{
	char res[20]={0};
	char glas[10]={'�', '�', '�', '�', '�', '�', '�', '�', '�', '�'};
	char soglas[23]={'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�','"','('};
	char addchars[3]={'�','�','-'};
	int i,j,k,m=0,counter,first=1, signflag=0, getnextflag=0;
	for(i=0;i<strlen(wor);i++)
	{
		if(strchr(glas,wor[i]) || strchr(glas,wor[i]+32))
			if(!first)
				{signflag=0;
				counter=0;
					k=i-1;
						while(!(strchr(glas,wor[k]) || strchr(glas,wor[k]+32)))
							{if(strchr(soglas,wor[k]) || strchr(soglas,wor[k]+32) || wor[k]=='-')
								counter++;
							else
								if((strchr(addchars,wor[k]) || strchr(addchars,wor[k]+32)))
									{signflag=1;
									break;}
								else
								if(place)
									{*nextsl=strlen(wor)+2000;
									*sllen=0;
									*slcount=0;
									return -1;}
								else
									{*nextsl=strlen(wor)+2000;
									*sllen=0;
									*slcount=0;
									return -2;}
							k--;}
					if(signflag)
						res[m]=k+1;
					else
						{k++;
						if(counter>=2)
							res[m]=k+1;
						else
							res[m]=k;
						}
					if(res[m]>place)
						{
						*nextsl=res[m];
						*sllen=res[m]-res[m-1];
						*slcount=m;
						return res[m-1];}
					if(res[m]==place)
						{
						getnextflag=1;
						if(wor[res[m]]=='�' && strlen(wor)-res[m]==1)
							{*nextsl=strlen(wor)+1300;
							*sllen=res[m]-res[m-1];
							*slcount=m;
							return res[m-1];}}
				m++;
				if(getnextflag)
					{*nextsl=res[m];
					*sllen=res[m]-res[m-1];
					*slcount=m;
					return res[m-1];}
				}
			else
			{if(i!=0)
				{k=i-1;
					while(k>=0)
						{if(!(strchr(soglas,wor[k]) || strchr(soglas,wor[k]+32)) && wor[k]!='-')
							if(place)
									{*nextsl=strlen(wor)+2000;
									*sllen=0;
									*slcount=0;
									return -1;}
								else
									{*nextsl=strlen(wor)+2000;
									*sllen=0;
									*slcount=0;
									return -2;}
						k--;}
				}
			if(res[m]>place)
						getnextflag=1;
					if(res[m]==place)
						getnextflag=1;
			m++;
			first=0;
			}
	}
if(first)
	m=1;
counter=0;
for(i=res[m-1];i<strlen(wor);i++)
	{if(!(strchr(soglas,wor[i]) || strchr(soglas,wor[i]+32) || strchr(glas,wor[i]) || strchr(glas,wor[i]+32) || strchr(addchars,wor[i]) || strchr(addchars,wor[i]+32)) && wor[i]!='-')
		if(place)
									{*nextsl=strlen(wor)+1000;
									*sllen=0;
									return -1;}
								else
									{*nextsl=strlen(wor)+1000;
									*sllen=0;
									return -2;}
	if(strchr(glas,wor[i]) || strchr(glas,wor[i]+32))
		counter++;}
if(first && !counter)
	{*sllen=0;
	return -1;}
*nextsl=strlen(wor)+1300;
*sllen=strlen(wor)-res[m-1];
*slcount=m;
return res[m-1];}

	
void ReadingPathCheck(char path[1024]) 			//������ � ������ ������ ������ �� ������������ ������
{while(fopen(path,"rt")==NULL)
	{printf("�������� ��������\n");
	scanf("%s",path);}
}

/*void ReadingMainVals(int* n, char path[1024], char OutPath[1024])   //���������� len � ������������ ������
{
	char test[256];
	printf("������� ���������� �������� � ������:");
	scanf("%s",test);
	ReadingIntCheck(n,test);
	printf("������� ���� ����� �����:");
	scanf("%s",path);
	ReadingPathCheck(path);
	printf("������� ���� ����� ������:");
	scanf("%s",OutPath);
	ReadingPathCheck(OutPath);
}*/

void Shift(char str[1024],int pos,int count, int len)  //c���� � ����
{int i;
for(i=len;i>=pos;i--)
	str[i+count]=str[i];
for(i=pos;i<count+pos;i++)
	str[i]=' ';
}

int JustifyWidth(char str[1024], int len, int left, int right, int TabFlag)	   //���������� ��������	you know what to do
{
int i, AdditionalEmp, 	AdditionalEmpForMod, EmpCount=0, first=1, CurrLen, TabCount=0, RealLen;
if(TabFlag)
	{left+=8;
	len-=8;}
CurrLen=right-left;
for(i=left;i<right;i++)
	{
		if(str[i]==' ')		
			EmpCount++;}
	if(EmpCount==0)
		return 0;
	AdditionalEmp=(len-CurrLen)/EmpCount;
	AdditionalEmpForMod=(len-CurrLen)%EmpCount;
	i=left;
	while(CurrLen!=len)
		{if(str[i]==' ')
			if(first)
				{Shift(str,i,AdditionalEmp+AdditionalEmpForMod,strlen(str));
				first=0;
				CurrLen+=(AdditionalEmp+AdditionalEmpForMod);
				i+=(AdditionalEmp+AdditionalEmpForMod+1);}
			else
				{Shift(str,i,AdditionalEmp,strlen(str));
				CurrLen+=AdditionalEmp;
				i+=(AdditionalEmp+1);
				}
		else
		i++;}
	return AdditionalEmp*EmpCount+AdditionalEmpForMod;
}


int StringAddAndDivergence(char str[1024],int len)       //���������� �������� ��������
{int RealLen, i, j, EmpCount=0, jw, k, CountForReal, TabCount=0, first=1, TabFlag=0, SpecialI, sl, additionalsign=0, nextsl, Poi, WordTakerEnd, WordTakerEndB, lenBuf, sllen, nextslFlag=0, SuspectTester, slcount, DualCavCount;
char WordTaker[500];
WordTaker[0]='\0';
lenBuf=len;
RealLen=strlen(str);
if(len==1)
	{for(i=0;i<strlen(str);i++)
		{for(k=strlen(str);k>=i;k--)
				str[k+1]=str[k];
		str[i]='\e';
		i++;}
	for(k=0;k<strlen(str);k++)
		str[k]=str[k+1];
	return 0;}
for(i=0;i<RealLen;i++)
	if(str[i]=='\t')
		TabCount++;
RealLen+=7*TabCount; 		 //� Tab 8 ��������
if(TabCount!=0)         //������� Tab
		{str[0]=' ';
		Shift(str,0,7,strlen(str));
		TabFlag=1;}
if(RealLen==len)			//������� ���� ������ �� ���� ������
	return 0;
//if(RealLen<len)				//���� ����������� ����� ������ ���������
//	{
//	JustifyWidth(str,len,0,strlen(str),TabFlag);
//	return 1;}
if(RealLen>len)				//���� ����������� ����� ������ ���������
	{
	i=0;
	if(len<=8 && TabCount)		//you know what to do
		{str[7]='\e';
		i+=8;
		TabFlag=0;
		TabCount=0;}
		while(i<strlen(str)-len)
		 {	if(TabCount && len>8)
			len-=8;
		 if(str[i+len+TabFlag*8]!=' ')       //� ������, ���� ������ � �����
			{for(j=i+TabFlag*8;j<i+len+TabFlag*8;j++)
					if(str[j]==' ')
						EmpCount++;		
			if(EmpCount>0)            //���� ��������� ���� � ������ - ��������� �� �����
				{j=i+len+TabFlag*8;
				while(str[j]!=' ')
					j--;
				SpecialI=j+1;				//������ ��������� �� �����
				DualCavCount=0;
				while(str[SpecialI]!='.' && str[SpecialI]!='?' && str[SpecialI]!='!' && str[SpecialI]!=',' && str[SpecialI]!=';' && str[SpecialI]!=':' && str[SpecialI]!=')' && str[SpecialI]!='\n' && str[SpecialI]!='\0' && str[SpecialI]!=' ' && str[SpecialI])
					{if(str[SpecialI]=='"')
						{DualCavCount++;
							if(DualCavCount==2)
								break;}
					WordTaker[SpecialI-j-1]=str[SpecialI];
					SpecialI++;}
				WordTakerEnd=SpecialI;
				WordTaker[SpecialI-j-1]='\0';
				if(TabFlag)
					SpecialI=len+TabFlag*8-j-1;
				else
					SpecialI=i+len-1-j;
				Poi=SpecialI;
				sl=SlDivivder(WordTaker,SpecialI,&nextsl,&sllen,&slcount);
				SpecialI=j+sl;
				if(sl==-1)
				{if(strlen(WordTaker)!=1)
				{j=i+len+TabFlag*8;
				if(str[WordTakerEnd]=='.' || str[WordTakerEnd]=='?' || str[WordTakerEnd]=='!' || str[WordTakerEnd]==',' || str[WordTakerEnd]==';' || str[WordTakerEnd]==':' || str[WordTakerEnd]=='-' || str[WordTakerEnd]=='"' || str[WordTakerEnd]=='(' || str[WordTakerEnd]==')')
					if(Poi!=1 && strlen(WordTaker)<len+Poi+1)
					j--;
					for(k=strlen(str);k>=j;k--)
						str[k+1]=str[k];
					if(str[i+len+1+TabFlag*8]==' ')
					for(k=i+len+1+TabFlag*8;k<strlen(str);k++)
						str[k]=str[k+1];
					if(str[j]==' ')
					{for(k=j;k<strlen(str);k++)
						str[k]=str[k+1];}}
				else
				j=i+len-1+TabFlag*8;
					}
				else
				if((sl!=0 && sl!=-2))				
				{
					j=SpecialI+1;
					for(k=strlen(str);k>=j;k--)
						str[k+1]=str[k];}
				str[j]='\e';
				jw=JustifyWidth(str,len,i,j-TabFlag*8,TabFlag);
				j-=i;
				i+=(jw+j+1);
				WordTaker[0]='\0';}
			else
				{j=i+TabFlag*8;						//���� ��� ��������
				DualCavCount=0;
					while(str[j]!='.' && str[j]!='?' && str[j]!='!' && str[j]!=',' && str[j]!=';' && str[j]!=':' && str[j]!=')' && str[j]!='\n' && str[j]!='\0' && str[j]!=' ')
				{if(str[j]=='"')
						{DualCavCount++;
							if(DualCavCount==2)
								break;}
				WordTaker[j-i-TabFlag*8]=str[j];
					j++;}
				WordTaker[j-i-TabFlag*8]='\0';
				WordTakerEndB=j-i-TabFlag*8;
				WordTakerEnd=j;
				sl=SlDivivder(WordTaker,len,&nextsl,&sllen,&slcount);
				if(sl==-2)
					sl=0;
				j=i+sl+TabFlag*8-1;
				SuspectTester=WordTakerEnd;
				while(slcount<=1 && (str[SuspectTester]=='.' || str[SuspectTester]=='?' || str[SuspectTester]=='!' || str[SuspectTester]==',' || str[SuspectTester]==';' || str[SuspectTester]==':' || str[SuspectTester]=='-' || str[SuspectTester]=='"' || str[SuspectTester]=='(' || str[SuspectTester]==')'))
					SuspectTester++;
				sllen+=(SuspectTester-WordTakerEnd);
				if(sl==-1 || nextsl==len || sllen>len+8*TabFlag)
				{j=i+len+TabFlag*8;
				if(len==WordTakerEndB && (str[WordTakerEnd]=='.' || str[WordTakerEnd]=='?' || str[WordTakerEnd]=='!' || str[WordTakerEnd]==',' || str[WordTakerEnd]==';' || str[WordTakerEnd]==':' || str[WordTakerEnd]=='-' || str[WordTakerEnd]=='"' || str[WordTakerEnd]=='(' || str[WordTakerEnd]==')'))
					j--;
				if(nextsl==len)
					nextslFlag=1;
					for(k=strlen(str);k>=j;k--)
						str[k+1]=str[k];
				}
				else
				if((sl!=0 && sl!=-2))				
				{j++;
					for(k=strlen(str);k>=j;k--)
						str[k+1]=str[k];
				}
				if((sl==0 || sl==-2) && i==0 && !(sllen>len) && !nextslFlag)
					for(k=strlen(str);k>=j;k--)
						str[k+1]=str[k];
				str[j]='\e';
				while((sl==0 || sl==-2) && i==0 && str[j+1]==' ' && !(sllen>len) && !nextslFlag)
					for(k=j+1;k<strlen(str);k++)
						str[k]=str[k+1];
				j-=i;
				i+=(j+1);
				WordTaker[0]='\0';
				}
			}
		else       								//���� �� ������ � ����� �� ������ ������ ������� � �����������
			{
			str[i+len+TabFlag*8]='\e';
			i+=len+1+TabFlag*8;
			}
		EmpCount=0;
		TabCount=0;
		TabFlag=0;
		nextslFlag=0;
		len=lenBuf;}
		/*if(str[i]!='\n')
			JustifyWidth(str,len,i,strlen(str),0);
		else
			JustifyWidth(str,len,i+1,strlen(str),0);*/
	return 2;
	}
}




void ToLayoutFormat(char* line, char* result, int len)    //����������, ���������, �����
{char CurrCh, CurrStr[1024];
int i=0;
CurrCh=line[i];
result[0] = '\0';
while(!(line[i]=='\0'))
	{if (CurrCh=='\n')
		{CurrStr[i]='\0';
		StringAddAndDivergence(CurrStr,len);
		strcat(CurrStr,"\e");
		if(CurrStr[0]=='\t')
			{Shift(CurrStr,0,7,strlen(CurrStr));
			CurrStr[7]=' ';}
		strcat(result,CurrStr);
		i=0;
		CurrStr[i]='\0';}
	else
		{CurrStr[i]=CurrCh;
		i++;
		}
		CurrCh=line[i];
	}
CurrStr[i]='\0';
		StringAddAndDivergence(CurrStr,len);
		strcat(CurrStr,"\e");
		if(CurrStr[0]=='\t')
			{Shift(CurrStr,0,7,strlen(CurrStr));
			CurrStr[7]=' ';}
		strcat(result,CurrStr);
}
	
/*
int main()
	{
		char st[1024];
		char result[1024];
		setlocale(LC_ALL, "Rus");
		SetConsoleCP(1251);
    	SetConsoleOutputCP(1251);
		scanf("%s",st);
		ToLayoutFormat(st,result,10);
		printf("\n%s",result);
		getch();
		return 0;
	}
*/
