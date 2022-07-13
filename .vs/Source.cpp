#include <iostream>
#include <fstream>
#include<cmath>
using namespace std;

	//a_complement
	void negate_a(int arr_a[],int arr_universal[]){
		cout << "{";
		for (int i = 0; i < 32; i++)
		{
			if (arr_a[i] == 0)
				cout << arr_universal[i]<<",";
		}
		cout << "}" << endl<<"[Bin A complement] : ";
		for (int j = 0; j < 32; j++)
		{
			if (arr_a[j] == 0)
				cout << 1;
			else
				cout << 0;
		}

	}

	//b_complement
	void negate_b(int arr_b[], int arr_universal[]){
		cout << "{";
		for (int i = 0; i < 32; i++)
		{
			if (arr_b[i] == 0)
				cout << arr_universal[i]<<",";
		}
		cout << "}" << endl<<"[ Bin B complement] :";
		for (int j = 0; j < 32; j++)
		{
			if (arr_b[j] == 0)
				cout << 1;
			else
				cout << 0;
		}

	}
	//a OR b
	void ORing(int arr_a[],int arr_b[],int arr_universal[]){
		cout << "{";
		int A[32] = { 0 };
		for (int i = 0; i < 32; i++) {
			if (arr_a[i] | arr_b[i]) {
				A[i] = 1;
				cout << arr_universal[i] << ",";
			}
		
		}
			cout << "}" << endl<<"[ Bin A Union B ] :";
			for (int j = 0; j < 32; j++)
			{
				cout << A[j];
			}

		
		
	}
	// a AND b
	 void Anding(int arr_a[], int arr_b[], int arr_universal[]){
		 cout << "{";
		 int A[32] = { 0 };
		for (int i = 0; i < 32; i++) {
			if (arr_b[i] & arr_a[i]) {
				cout << arr_universal[i] << ",";
				A[i] = 1;
			}
		}
		cout << "}"<< endl<<"[ Bin A Intersection B ] :";
		for (int j = 0; j < 32; j++)
		{
			cout << A[j];
		}

	}
	 //A-B
	 void Sub_a_b(int arr_a[], int arr_b[], int arr_universal[]){
		 int A[32] = {0};
		 cout << "{";
		 for (int i = 0; i < 32; i++) {
			 if (arr_a[i] == 1 && arr_b[i] == 0) {
				 A[i] = 1;
				 cout << arr_universal[i] << ",";
			 }
		 }
		cout << "}"<<endl<<"[Bin A - B] : ";
		for (int j = 0; j < 32; j++)
		{
			cout << A[j];
		}
	}
	void xnor(int arr_a[], int arr_b[], int arr_universal[]){ //A xnor B
		cout << "{";
		int A[32] = {0};
		for (int i = 0; i < 32; i++) {
			if ((arr_a[i] == 1 && arr_b[i] == 1) || (arr_a[i] == 0 && arr_b[i] == 0)) {
				A[i] = 1;
				cout << arr_universal[i] << ",";
			}
		}
		cout << "}"<<endl<<"[Bin: A XNOR B ] :";
		for (int j = 0; j < 32; j++)
			cout << A[j];

	}
	// A*B
	void cross(int arr_a[], int arr_b[], int arr_universal[])	{
		cout << "{";
		for (int i = 0; i < 32; i++) {
			if (arr_a[i] == 1)
				for (int j = 0; j < 32; j++) {
					if (arr_b[j] == 1)
						cout << "(" << arr_universal[i] << "," << arr_universal[j] << ")" << ",";

				}
		}
		cout << "}";
	}
	//power set 
	void power_set_xor(int arr_a[], int arr_b[], int arr_universal[])
	{
		double count = 0;
		for (int i = 0; i < 32; i++) {
			if ((arr_a[i] == 1 && arr_b[i] == 0) || (arr_a[i] == 0 && arr_b[i] == 1)) {
				count++;
			}
		}
		int o = 0;
		cout << "[A Xor B]: { ";
		int* Pro_Xor = new int[count];
			for (int j = 0; j < 32; j++) {
				if ((arr_a[j] == 1 && arr_b[j] == 0) || (arr_a[j] == 0 && arr_b[j] == 1)) {
					Pro_Xor[o] = arr_universal[j];
					cout << Pro_Xor[o] << ",";
					o++;
				}
		}
		cout << "}" << endl;
		double p = pow(2, count);
		cout << "Cardinality = " << p << endl;
		cout << "[power subset of A xor B]  :";
			for (int j = 0; j < p; j++) {
				cout << "{ ";
				for (int k = 0; k < count; k++) {
					if (j & (1 << k))
						cout << Pro_Xor[k]<<",";
				}
				cout << "} ";
			}
				
			}
	

	//complement of a fuzzy 
	void complement_of_fuzzy_A(double Arr[]) {
		cout << "[A compl. ] : {";
		for (int i = 0; i < 10; i++) {
			char x = 97+i;
			cout << 1 - Arr[i] << x << ", ";
		}
		cout << "}";
	}
	void complement_of_fuzzy_B(double Arr[]) {
		cout << "[B compl. ] : {";
		for (int i = 0; i < 10; i++) {
			char x = 97 + i;
			cout << 1 - Arr[i] << x << ", ";
		}
		cout << "}";
	}
	//intersection_of_fuzzy
	void intersection_of_fuzzy(double Arr1[], double Arr2[]) {
		cout << "[A int. B] : {";

		for (int i = 0; i < 10; i++) {
			char x = 97 + i;
			if (Arr1[i] < Arr2[i])
				cout << Arr1[i] << x<<", ";
			else
			cout << Arr2[i] << x<<" ,";

		}
		cout << "}";
	}
	//union_of_fuzzy
	void union_Fuzzy (double Arr1[], double Arr2[]) {
		cout << "[A union B] : {";
		for (int i = 0; i < 10; i++) {
			char x = 97 + i;
			if (Arr1[i] > Arr2[i])
				cout << Arr1[i] << x<<", ";
			else
				cout << Arr2[i] << x<<", ";

		}
		cout << "}";
	 }
	//difference between two fuzzy
	void difference(double Arr1[], double Arr2[]) {
		cout << "A difference B (A-B) / [A int.(compl. B)] : { ";
		double Arr[10];
		for (int i = 0; i < 10; i++) {
			Arr[i] = 1 - Arr2[i];
		}
		for (int j = 0; j < 10; j++) {
			char x = 97 + j;
			if (Arr[j] < Arr1[j])
				cout << Arr[j] << x << ", ";
			else
				cout << Arr1[j] << x << ", ";

		}
		cout << "}";
	}
	//least multiple common for two positive numbers
	int  GCD(int a, int b) {
		cout << "gcd("<< a<<","<<b<<")"<<" ";
		if (b == 0) 
		 return a ;
		else
		 return GCD(b, a % b);
	}

	int main() {
		cout <<  "-------------_Data for Question #1------------";
		cout << endl << "_____________________________________________________________________________________________________________________" << endl;
		ifstream F;
		F.open("Question 1.txt", ios::in);
		int Universal[32];
		//Universal
		for (int i = 0; i < 32; i++) {
			Universal[i] = i + 1;
		}
		int Bin_Set_A[32] = { 0 };
		int Bin_Set_B[32] = { 0 };

		//read set_a;
		cout << "Set A :";
		int count_a;
		int x;
		F >> count_a;
		cout << "{";
		for (int m = 0; m < count_a; m++) {
			F >> x;
			cout << x << ",";
			Bin_Set_A[x - 1] = 1;
		}
		cout << "}";

		//print Bin_Set_A
		cout <<endl<< "Bin Set A :";
		for (int o = 0; o < 32; o++) {
			cout << Bin_Set_A[o];
		}

		cout << endl;
		//read set_b;
		cout << "Set B :";
		int count_b;
		int y;
		F >> count_b;
		cout << "{";
		for (int n = 0; n < count_b; n++) {
			F >> y;
			cout << y << ",";
			Bin_Set_B[y - 1] = 1;
		}
		cout << "}";
		//print Bin_Set_B
		cout << endl << "Bin Set B :";
		for (int t = 0; t < 32; t++) {
			cout << Bin_Set_B[t];
		}

		cout << endl;
		int choice;
		cout << endl << "-------------_Data for Question #2------------" ;
		cout << endl << "_____________________________________________________________________________________________________________________" << endl;

		double S[10] = { 0.0 };
		double T[10] = { 0.0};
		int n1, n2;
		ifstream F2;
		F2.open("Question 2.txt", ios::in);
		F2 >> n1;
		cout << "S : {";
		for (int i = 0; i < n1; i++) {
			F2 >> S[i];
			char k = 97 + i;
			cout << S[i] << k<<",";
		}
		cout << "}";
		cout << endl;
		F2 >> n2;

		cout << "T : { ";
		for (int j = 0; j < n2; j++) {
			F2 >> T[j];
			char v = 97 + j;
			cout << T[j] << v<<",";

		}
		cout << "}";
		int h, l;
		ifstream F3;
		F3.open("Question 3.txt", ios::in);
		F3 >> h;
		cout << endl <<endl<< "-------------_Data for Question #3------------";
		cout << endl << "_____________________________________________________________________________________________________________________" << endl;
		cout << endl<<"1st number : "<<h;
		F3 >>  l;
		cout <<endl<<"2nd number : "<< l;

		while (1) {
			cout << endl << "_____________________________________________________________________________________________________________________" << endl;
			cout << " 1. question #1 \n ";
			cout << "2. question #2 \n ";
			cout << "3. question #3 \n ";
			cout << "4. Exit \n";
			cout << "Enter the number of question  : ";
			cin >> choice;
			switch (choice) {
			case 1:
				while (1) {
					int w;
					cout << endl << "_____________________________________________________________________________________________________________________" << endl;
					cout << " 1. ~A\n";
					cout << " 2. ~B\n";
					cout << " 3. A Union B \n";
					cout << " 4. A Intersection B \n";
					cout << " 5. A-B \n";
					cout << " 6. A Xnor B \n ";
					cout << "7. A cross B \n";
					cout << " 8. power set of A xor B \n ";
					cout << "9. Back to the Main Menu \n";
					cout << "Enter Your Choice : ";
					cin >> w;

					if (w == 1) {
						cout << endl << "_____________________________________________________________________________________________________________________" << endl;
						cout << "[A complement] : ";
						negate_a(Bin_Set_A, Universal);
					}
					else if (w == 2) {
						cout << endl << "_____________________________________________________________________________________________________________________" << endl;
						cout << "[B complement] : ";
						negate_b(Bin_Set_B, Universal);
					}
					else if (w == 3) {
						cout << endl << "_____________________________________________________________________________________________________________________" << endl;
						cout << "[A Union B] : ";
						ORing(Bin_Set_A, Bin_Set_B, Universal);
					}
					else if (w == 4) {
						cout << endl << "_____________________________________________________________________________________________________________________" << endl;
						cout << "[A Intersection B] : ";
						Anding(Bin_Set_A, Bin_Set_B, Universal);
					}
					else  if (w == 5) {
						cout << endl << "_____________________________________________________________________________________________________________________" << endl;
						cout << "[ A Difference B] : ";
						Sub_a_b(Bin_Set_A, Bin_Set_B, Universal);
					}
					else if (w == 6) {
						cout << endl << "_____________________________________________________________________________________________________________________" << endl;
						cout << "[A Xnor B] : ";
						xnor(Bin_Set_A, Bin_Set_B, Universal);
					}
					else if (w == 7) {
						cout << endl << "_____________________________________________________________________________________________________________________" << endl;
						cout << "[A cross B] :";
						cross(Bin_Set_A, Bin_Set_B, Universal);
					}
					else if (w == 8) {
						cout << endl << "_____________________________________________________________________________________________________________________" << endl;
						power_set_xor(Bin_Set_A, Bin_Set_B, Universal);
					}
					else if (w == 9) {
						cout << endl << "_____________________________________________________________________________________________________________________" << endl;
						cout << "Back to Main Menu ";
						break;
					}
					else
					{
						cout << endl << "_____________________________________________________________________________________________________________________" << endl;
						cout << "Invalid choice";

					}
				}
				break;
			case 2:
				while (1) {
					int c;
					cout << endl << "_____________________________________________________________________________________________________________________" << endl;
					cout << "1.complement of a fuzzy set S & complement of a fuzzy set T " << endl;
					cout << "2.Intersection of two fuzzy sets S and T" << endl;
					cout << "3.The difference between two fuzzy sets S and T" << endl;
					cout << "4.The union of two fuzzy sets S and T" << endl;
					cout << "5.Back to the Main Menue" << endl;
					cout << "Enter Your Choice : ";
					cin >> c;
					if (c == 1) {
						cout << endl << "_____________________________________________________________________________________________________________________" << endl;
						complement_of_fuzzy_A(S);
						cout << endl;
						complement_of_fuzzy_B(T);
					}
					else if (c == 2) {
						cout << endl << "_____________________________________________________________________________________________________________________" << endl;
						intersection_of_fuzzy(S, T);
						cout << endl;
					}					

					else if (c == 3) {
						cout << endl << "_____________________________________________________________________________________________________________________" << endl;
						difference(S, T);
						cout << endl;
					}

					else if (c == 4) {
						cout << endl << "_____________________________________________________________________________________________________________________" << endl;
						union_Fuzzy(S, T);
						cout << endl;
					}
					else if (c == 5) {
						cout << "Back to Main Menu ";
						break;
					}
					else
						cout << "Invalid choice";
			}
				break;
			    case 3:
				while(1){
					cout << endl << "_____________________________________________________________________________________________________________________" << endl;
					cout << "1.Compute least multiple common for two positive numbers (LCM) " << endl;
				cout << "2.Back to the Main Menue" << endl;
				cout << "Enter Your Choice : ";
				int j;
				cin >> j;
				if (j == 1) {
					int n1, n2;
					if (h > l) {
						n1 = h;
						n2 = l;
					}
					else {
						n1 = l;
						n2 = h;
					}
					float b;
					cout << endl << "_____________________________________________________________________________________________________________________" << endl;
					b = GCD(n1, n2);
					cout << endl << "least multiple common for two positive numbers (LCM) : = " << (h * l) / b;
				}
				else if (j == 2) {
					cout << endl << "_____________________________________________________________________________________________________________________" << endl;
					cout << "2.Back to the Main Menue" << endl;
					break;
				}
				else
				{
					cout << endl << "_____________________________________________________________________________________________________________________" << endl;
					cout << "Invalid choice";
				}
				}				
				break;
				case 4:
					cout << endl << "_____________________________________________________________________________________________________________________" << endl;
					cout << "---------End of Program------- ";
					cout << endl << "_____________________________________________________________________________________________________________________" << endl;
					exit(0);
				break;
				default:
					cout << endl << "_____________________________________________________________________________________________________________________" << endl;
					cout << "invalid choice";
			}
		}

		



		return 0;
	}