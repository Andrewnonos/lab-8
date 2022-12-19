#include<iostream>
#include<cstdint>
#include<cmath>

uint64_t ArithmProgression(int n);
bool PrimeNum(int a);
void MagickNumbers(uint64_t i, uint64_t j, uint64_t n, uint64_t* counter);

int main(void){
	uint64_t n;
	uint64_t summ = 0;

	std::cin >> n;

	// AP(n-1) + 1 = starting number of 'n' row
	uint64_t starting_num = ArithmProgression(n-1)+1;

	for(int i = 0; i < n; i++){
	    if(PrimeNum(starting_num+i)){
	        uint64_t prime_counter = 0;

	        MagickNumbers(0, i, n, &prime_counter);

	        if(prime_counter > 1)
	            summ += starting_num+i;
	    }
	}

	std::cout << summ;

	return 0;
}

uint64_t ArithmProgression(int n){
	return (1+n)*n/2;
}

bool PrimeNum(int n){
	for(int i = 2; i < sqrt(n); i++){
		if(n%i == 0)
			return false;
	}

    return true;
}

void MagickNumbers(uint64_t i, uint64_t j, uint64_t n, uint64_t* counter){
	if(*counter > 1)
		return;

	if(i > 0){
		if(PrimeNum(ArithmProgression(n-2+i)+j-1)){
			(*counter)++;
			MagickNumbers(i-1, j-1, n, counter);
		}
		if(PrimeNum(ArithmProgression(n-1+i)+j-1)){
			(*counter)++;
			MagickNumbers(i, j-1, n, counter);
		}
		if(PrimeNum(ArithmProgression(n+i)+j-1)){
			(*counter)++;
			MagickNumbers(i+1, j-1, n, counter);
		}
	}

	if(i+2 < n){
	    if(PrimeNum(ArithmProgression(n-2+i)+j+2)){
			(*counter)++;
			MagickNumbers(i-1, j+1, n, counter);
	    }
	}

	if((i+1 < n) && (PrimeNum(ArithmProgression(n-2+i)+j+1))){
		(*counter)++;
		MagickNumbers(i-1, j, n, counter);
	}
	if((i+1 < n) && (PrimeNum(ArithmProgression(n-1+i)+j+2))){
		(*counter)++;
		MagickNumbers(i, j+1, n, counter);
	}

	if(PrimeNum(ArithmProgression(n+i)+j+1)){
		(*counter)++;
		MagickNumbers(i+1, j, n, counter);
	}
	if(PrimeNum(ArithmProgression(n+i)+j+2)){
		(*counter)++;
		MagickNumbers(i+1, j+1, n, counter);
	}


}
