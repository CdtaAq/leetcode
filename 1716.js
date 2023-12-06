/**
 * @param {number} n
 * @return {number}
 */
var totalMoney = function(n) {
    const weeks = Math.floor(n / 7);
    const days = n % 7;
    const lowest = 28;
    const highest = 28 + 7 * (weeks - 1);
    let total = (lowest + highest) * weeks / 2;

    const monday = weeks + 1;
    for (let i = 0; i < days; i++) {
        total += i + monday;
    }

    return total;    
};
