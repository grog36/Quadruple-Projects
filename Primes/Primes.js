//Gregory Ecklund
//September 2022

let maxNum = 10000; //Changeable upper-limit
let isPrime = true;
let listOfPrimes = [];

for(let i = maxNum; i >= 2; i--) {
	for (let t = 2; t < (Math.floor(Math.sqrt(i) + 1)); t++) {
		if (i % t === 0) {
			isPrime = false;
		}
	}
	if (isPrime) {
		listOfPrimes.push(i);
	}
	else {
		isPrime = true;
	}
}

console.log(listOfPrimes);