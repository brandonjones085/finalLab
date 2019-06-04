/*******************************************************************************
** Author:       Brandon Jones
** Date:         06/03/2019
** Description:  The main file where the program is run.
*******************************************************************************/



#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

//Prototypes
int recursive(int); 
int iterative(int); 



int main()
{
	int num; 


	while (true)
	{

		std::cout << "Please enter a number: ";
		std::cin >> num;

		double duration, duration1;
		clock_t start, start1;

		start = clock();

		//begins run time measurement
		start = clock();

		//function call
		int output = recursive(num);

		//Ends run time measurement, Subtracts stop from start time
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		std::cout << std::endl << std::endl << std::endl;

		//User output
		std::cout << "Fibonaci number using recursion: "<< std::endl;
		std::cout << "It took " << duration << " clicks " << std::endl;
		std::cout << std::endl;




		//begins run time measurement
		start1 = clock();

		//function call
		iterative(num);

		//Ends run time measurement, Subtracts stop from start time
		duration1 = (clock() - start1) / (double)CLOCKS_PER_SEC;


		std::cout << "\nFibonaci number using iteration " << std::endl;
		std::cout << "It took " << duration1 << " clicks " << " and " << ((float)duration1 / CLOCKS_PER_SEC) << std::endl;


	}



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
	return (recursive(i - 1) + recursive(i - 2)); 
}

/*******************************************************************************
** Description:  Takes in an int and uses iteration to find the fibonaci sequence.
//source: https://www.tutorialspoint.com/cplusplus-program-to-find-fibonacci-numbers-using-iteration
*******************************************************************************/
int iterative(int n)
{
	int zero = 0, one = 1, two = 0; 
	for (int i = 0; i < n; i++)
	{
		
		zero = two; 
		two = one; 
		one = zero + two; 

	}
	
	return one; 
}