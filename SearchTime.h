#pragma once

#include <string>
#include <ctime>

using namespace std;

// Representa um objeto imutável com o tempo inicial e final da pesquisa.
class SearchTime {
public:
	SearchTime() = default;
	SearchTime(time_t initialTime, time_t finalTime);

	time_t getInitialTime() const;
	void setInitialTime(time_t tempo);

	time_t getFinalTime() const;
	void setFinalTime(time_t tempo);

	// Calcula o tempo de duração da pesquisa em segundos.
	time_t duration();

	// Calcula o tempo de duração da pesquisa em segundos.
	static time_t duration(time_t initialTime, time_t finalTime);

private:
	// Representa o tempo inicial da pesquisa.
	time_t initialTime;
	
	// Representa o tempo final da pesquisa.
	time_t finalTime;
};