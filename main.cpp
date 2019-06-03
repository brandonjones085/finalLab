/*******************************************************************************
** Author:       Brandon Jones
** Date:         06/03/2019
** Description:  The main file where the program is run.
*******************************************************************************/



#include <iostream>
#include <chrono>

int recursive(int); 
void iterative(int); 

using namespace std::chrono; 


int main()
{
	int num; 

	std::cout << "Please enter a number: "; 
	std::cin >> num; 
  

	//begins run time measurement
	auto start1 = high_resolution_clock::now(); 

	//function call
	int output = recursive(num); 

	//Ends run time measurement
	auto stop1 = high_resolution_clock::now(); 
	
	//Subtracts stop from start time
	auto duration1 = duration_cast<microseconds>(stop1 - start1);


	//begins run time measurement
	auto start2 = high_resolution_clock::now();

	//function call
	iterative(num);

	//Ends run time measurement
	auto stop2 = high_resolution_clock::now();

	//Subtracts stop from start time
	auto duration2 = duration_cast<microseconds>(stop2 - start2);


	//User output
	std::cout << "Fibonaci number using recursion: " << output << std::endl; 
	std::cout << "Duration: " << duration1.count() << std::endl; 
	std::cout << std::endl; 
	std::cout << "Fibonaci number using iteration " << std::endl;
	std::cout << "Duration: " << duration2.count() << std::endl;
	
	
}


/*******************************************************************************
** Description:  Takes in an int and uses recursion to find the fibonaci sequence.
//source: https://stackoverflow.com/questions/1518726/recursive-fibonacci
*******************************************************************************/

int recursive(int i)
{
	if (i == 0)
	{
		return 0; 
	}
	else if (i == 1)
	{
		return 1; 
	}
	return recursive(i - 1) + recursive(i - 2); 
}

/*******************************************************************************
** Description:  Takes in an int and uses iteration to find the fibonaci sequence.
//source: https://www.tutorialspoint.com/cplusplus-program-to-find-fibonacci-numbers-using-iteration
*******************************************************************************/

void iterative(int n)
{
	int zero = 0, one = 1, two = 0; 
	for (int i = 0; i < n; i++)
	{
		std::cout << zero << " "; 
		two = zero + one; 
		zero = one; 
		one = two; 
	}
	
}