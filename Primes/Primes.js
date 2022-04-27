let n = 100
let test = true

var listOfPrimes = []

for (i=n; i>=2; i--) {
    for(t=2; t<i; t++) {
        if(i%t==0) {
            test = false
        }
    }
    if(test == true) {
        listOfPrimes.push(i)
    }
    test = true
}

console.log(listOfPrimes)