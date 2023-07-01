#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void showweb(){
	cout << "\t\t\t\tKrishnaBazar.com \n \t\tWelcome to the Biggest Shopping Mall of INDIA \n \t\t\tPOPULAR ITEMS OF THE DAY\n";
}

struct data{
	string InvoiceNo;
	string StockCode;
	string Description;
	string Quantity;
	string InvoiceDate;
	double UnitPrice;
	string CustomerID;
	string Country;
	int rating;
};

bool compare1(data a,data b){
	return a.UnitPrice < b.UnitPrice;
}

bool compare2(data a,data b){
	return a.UnitPrice > b.UnitPrice;
}

class item{
	std::vector<data> v;
	int l = 0;
public:
	void additem(struct data d){
		v.push_back(d);
		l++;
	}
	void viewitems();
	void sort1(){
		heapSort1(l);
		viewitems();
	}
	void sort3(){
		heapSort3(l);
		viewitems();
	}
	void sort4(){
		heapSort4(l);
		viewitems();
	}
	void sort2(){
		heapSort2(l);
		viewitems();
	}
	void heapify2(int n, int i) 
	{ 
	    int largest = i;
	    int l = 2*i + 1; 
	    int r = 2*i + 2;
	    if (l < n && v[l].rating > v[largest].rating) 
	        largest = l; 
	    if (r < n && v[r].rating > v[largest].rating) 
	        largest = r; 
	    if (largest != i) 
	    { 
	        swap(&v[i],&v[largest]); 
	        heapify2(n, largest); 
	    } 
	}
	void heapSort2(int n) 
	{ 
		int t = 1;
	    for (int i = n / 2 - 1; i >= 0; i--) 
	        heapify2(n, i); 
	    for (int i=n-1; i>=n-1; i--) 
	    { 
	    	if(t == 20)
	    		return ;
	        swap(&v[0], &v[i]); 
	        heapify2(i, 0); 
	        t++;
	    } 
	}
	/*void Sort(){
		char c;
		cout << "Based on rating or price(R/P)"<< endl;
		cin >> c;
		switch(c){
			case 'R':
			Sort
		}
	}*/
	void heapify1(int n, int i) 
	{ 
	    int largest = i;
	    int l = 2*i + 1; 
	    int r = 2*i + 2;
	    if (l < n && v[l].rating > v[largest].rating) 
	        largest = l; 
	    if (r < n && v[r].rating > v[largest].rating) 
	        largest = r; 
	    if (largest != i) 
	    { 
	        swap(&v[i],&v[largest]); 
	        heapify1(n, largest); 
	    } 
	} 
	
	void heapify3(int n, int i) 
	{ 
	    int largest = i;
	    int l = 2*i + 1; 
	    int r = 2*i + 2;
	    if (l < n && v[l].UnitPrice < v[largest].UnitPrice ) 
	        largest = l; 
	    if (r < n && v[r].UnitPrice < v[largest].UnitPrice ) 
	        largest = r; 
	    if (largest != i) 
	    { 
	        swap(&v[i],&v[largest]); 
	        heapify3(n, largest); 
	    } 
	} 
	void heapify4(int n, int i) 
	{ 
	    int largest = i;
	    int l = 2*i + 1; 
	    int r = 2*i + 2;
	    if (l < n && v[l].UnitPrice > v[largest].UnitPrice) 
	        largest = l; 
	    if (r < n && v[r].UnitPrice > v[largest].UnitPrice) 
	        largest = r; 
	    if (largest != i) 
	    { 
	        swap(&v[i],&v[largest]); 
	        heapify4(n, largest); 
	    } 
	}
	void heapSort1(int n) 
	{ 
	    for (int i = n / 2 - 1; i >= 0; i--) 
	        heapify1(n, i); 
	    for (int i=n-1; i>=n-1; i--) 
	    { 
	        swap(&v[0], &v[i]); 
	        heapify1(i, 0); 
	    } 
	}
	void heapSort3(int n) 
	{ 
	    for (int i = n / 2 - 1; i >= 0; i--) 
	        heapify3(n, i); 
	    for (int i=n-1; i>=n-1; i--) 
	    { 
	        swap(&v[0], &v[i]); 
	        heapify3(i, 0); 
	    } 
	}
	void heapSort4(int n) 
	{ 
	    for (int i = n / 2 - 1; i >= 0; i--) 
	        heapify4(n, i); 
	    for (int i=n-1; i>=n-1; i--) 
	    { 
	        swap(&v[0], &v[i]); 
	        heapify4(i, 0); 
	    } 
	}
	void swap(struct data *A, struct data *B){
    	struct data temp = *A;
    	*A = *B;
    	*B = temp;
	}
	void kpopular(){
		sort2();
	}
	void print(int);
};

void searchitem(){
	item i;
	system("clear");
	showweb();
	string need,astring,str,s,c = "c";
	char y,x;
	int t,a;
	double min = 0,max = 100,j;
	char eater;
	struct data d;
	fstream fin;
	fin.open("data.csv",ios::in);
	cout << " Enter the product name "<< endl;
	cin.ignore();
	getline(cin,need);
	cout << "Want to apply any filters(Y/N)";
	cin >> y;
		if(y == 'Y'){
			cout << "1. Based on Price\n" << "2. Select the product Country\n"<< "3. Both\n";
			cin >> t;
			switch(t){
				case 1:
					cout << "Enter Range(eg. min-max)"<< endl;
					cin >> min >> eater >> max;break;
				case 2:
					cout <<"Chose number\n" << " 1.United Kingdom\n 2.France\n 3.Germany\n 4.Switzerland" <<endl;
					cin >> t;
					switch(t){
						case 1:
						c =  "United Kingdom";break;
						case 2:
						c = "France";break;
						case 3:
						c = "Germany";break;
						case 4:
						c = "Switzerland";break;
					}break;
				case 3:
					cout << "Enter Range(eg. min-max)"<< endl;
					cin >> min >> eater >> max;
					cout << "chose number\n" << " 1.United Kingdom\n 2.France\n 3.Germany\n 4.Switzerland" <<endl;
					cin >> t;
					switch(t){
						case 1:
						c =  "United Kingdom";break;
						case 2:
						c = "France";break;
						case 3:
						c = "Germany";break;
						case 4:
						c = "Switzerland";break;
						default:
						cout << "Not correct code ";
					}break;
			}	
		}
	getline(fin, astring);
		for(int t = 0;t < 100000; t++){
			getline(fin ,s,',');
			d.InvoiceNo = s;
			getline(fin ,s,',');
			d.StockCode = s;
			getline(fin ,s,',');
			d.Description = s;
			getline(fin ,s,',');
			d.Quantity = s;
			getline(fin ,s,',');
			d.InvoiceDate = s;
			fin >> j;
			d.UnitPrice = j;
			getline(fin ,s,',');
			d.CustomerID = s;
			getline(fin ,s,',');
			getline(fin ,s);
			d.Country = s;
			d.rating = rand()%11;
			str = d.Description;
			std::size_t found = str.find(need);
		  	if (found!=std::string::npos){
		  		if(d.UnitPrice > min && d.UnitPrice < max){
		  			if(c != "c"){
						str = d.Country;
						std::size_t found = str.find(c);
			  			if (found!=std::string::npos)
			  				i.additem(d);
					}
					else
						i.additem(d);
		  		}
		  	}
		}
		i.viewitems();
}

void item::print(int k){
	char a;
	printf("%5d %40s %6s %10.2lf %6d %10s\n",k , v[k-1].Description.c_str() ,v[k-1].Quantity.c_str(), v[k-1].UnitPrice ,v[k-1].rating, v[k-1].Country.c_str());
	cout << "1.Confirm(C) 2.back to main menu(B)"<<endl;
	cin >> a;
	if(a == 'C'){
		cout << "Thanks for the purchase \nProduct will be delivered within two to three working days"<<endl;
	}
	else
		searchitem();
}

void item::viewitems(){
	int k = 20;
	int j;
	char y;
	if(l > 20){
		cout << "Number\t\t\tDescription\tQuantity UnitPrice Rating\tCountry"<<endl;
		for (int t = 0; t < k; ++t){
			printf("%6d %35s %5s %5.2lf %6d\t\t%10s\n",t+1 , v[t].Description.c_str() ,v[t].Quantity.c_str(), v[t].UnitPrice ,v[t].rating, v[t].Country.c_str());
			if(t%20 == 19 && k != l){
				cout << "Searchitems(S)  \tSelectproduct(P)\tNext page(Y)\tFilter(F)\tExit(E) " << endl;
				cin >> y;
				if(y == 'Y' && k + 20 < l)
					k +=20;
				else if(y == 'F'){
					cout << " 1.Sort price low to high(A) or high to low(B)\n 2.Sort based on rating(R) " << endl;
					cin >> y;
					if(y == 'R')
						sort1();
					else if(y == 'B')
						sort4();
					else
						sort3();
				}
				else if(y == 'S')
					searchitem();
				else if(y == 'P'){
					cout << "Enter the product serial code"<<endl;
					cin >> j;
					print(j);
				}
				else
					return;
			}
		}
	}
	else if(l != 0){
		cout << "Number\t\t\tDescription\tQuantity UnitPrice Rating\tCountry"<<endl;
		for (int t = 0; t < l; ++t){
			printf("%5d %35s %5s %5.2lf %6d\t\t%10s\n",t+1 , v[t].Description.c_str() ,v[t].Quantity.c_str(), v[t].UnitPrice ,v[t].rating, v[t].Country.c_str());
			cout << "Searchitems(S)  \tSelectproduct(P)\tFilter(F)\tExit(E) " << endl;
			cin >> y;
			if(y == 'F'){
				cout << " 1.Sort price low to high(A) or high to low(B)\n 2.Sort based on rating(R) " << endl;
				cin >> y;
				if(y == 'R')
					sort1();
				else if(y == 'B')
					sort4();
				else
					sort3();
			}
			else if(y == 'S')
				searchitem();
			else if(y == 'P'){
				cout << "Enter the product serial code"<<endl;
				cin >> j;
				print(j);
			}
			else
				return;
		}
	}
	else
	{
		cout << " Sorry product is not available with us "<< endl;
		cout << "Searchitems(S)  \tSelectproduct(P)\tNext page(Y)\tFilter(F)\tExit(E) " << endl;
				cin >> y;
				if(y == 'Y' && k + 20 < l)
					k +=20;
				else if(y == 'F'){
					cout << " 1.Sort price low to high(A) or high to low(B)\n 2.Sort based on rating(R) " << endl;
					cin >> y;
					if(y == 'R')
						sort1();
					else if(y == 'B')
						sort4();
					else
						sort3();
				}
				else if(y == 'S')
					searchitem();
				else if(y == 'P'){
					cout << "Enter the product serial code"<<endl;
					cin >> j;
					print(j);
				}
				else if(y == 'N')
					return;
	}
}

int main(){
	system("clear");
	showweb();
	string astring,s;
	struct data d;
	item i1;
	fstream fin;
	fin.open("data.csv",ios::in);
	double j;
	getline(fin, astring);
	for(int t = 0;t < 100000; t++){
		getline(fin ,s,',');
		d.InvoiceNo = s;
		getline(fin ,s,',');
		d.StockCode = s;
		getline(fin ,s,',');
		d.Description = s;
		getline(fin ,s,',');
		d.Quantity = s;
		getline(fin ,s,',');
		d.InvoiceDate = s;
		fin >> j;
		d.UnitPrice = j;
		getline(fin ,s,',');
		d.CustomerID = s;
		getline(fin ,s,',');
		getline(fin ,s);
		d.Country = s;
		d.rating = rand()%11;	
		i1.additem(d);	
	}
	i1.kpopular();
	return 0;
}