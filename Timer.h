#ifndef __ECE_231_TIMER_H__

#define __ECE_231_TIMER_H__



#include <chrono>

#include <string>

#include <iostream>



class Timer

{

	private:



	typedef std::chrono::time_point<std::chrono::high_resolution_clock> tpoint;



	tpoint _start;

	std::string _message;



	Timer(const Timer&);

	Timer& operator=(const Timer&);



	public:



	Timer() : _start(std::chrono::high_resolution_clock::now())

	{

	}



	Timer(std::string&& message) : _start(std::chrono::high_resolution_clock::now())

	{

		_message = message;

	}



	~Timer()

	{

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff = end-_start;



		std::cout << _message << diff.count() << "s" << std::endl;

	}

};





#endif // __ECE_231_TIMER_H__
