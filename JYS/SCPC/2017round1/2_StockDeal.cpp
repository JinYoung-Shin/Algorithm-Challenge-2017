#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Answer;
int N;
int arr[200010];

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		cin >> N;
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		
		int status;
		if(arr[0] < arr[1]) { // 증가 
			status = 1;
			Answer = Answer + 2;
		} else status = 0; // 감소 또는 그대로 
		
		for(int i = 2; i < N; i++) {
			if(status == 1 && arr[i] < arr[i-1]) { // 꺽이는 점, 감소  
				status = 0;
			} else if(status == 0 && arr[i] > arr[i-1]) { // 꺽이는 점 증가 
				status = 1;
				Answer = Answer + 2;
			}
		}		
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}