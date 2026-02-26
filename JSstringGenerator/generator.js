const fs = require('fs');

function generateUnixTime(start, index) {
    return (start + index).toString();
}

function generatePrice(index) {
    const base = 100 + (index % 900) * 0.123;
    return base.toFixed(3);
}

function generateName(index) {
    return `task_${index}`;
}

let startUnix = 1700000000;
let output = '';

for (let i = 1; i <= 1000; i++) {
    let time = generateUnixTime(startUnix, i);
    let price = generatePrice(i);
    let name = generateName(i);

    output += `${time}\n${price}\n${name}\n\n`;
}

fs.writeFileSync('../tasks.txt', output, 'utf8');