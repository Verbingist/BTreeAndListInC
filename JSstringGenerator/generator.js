const fs = require('fs');

function generatePrice(index) {
    let base = 100 + (index % 900) * 0.123;
    return base.toFixed(3);
}

function generateName(index) {
    return `task_${index}`;
}

let startUnix = 1700000000;
let keys = [];

for (let i = 1; i <= 1000; i++) {
    keys.push(startUnix + i);
}

for (let i = keys.length - 1; i > 0; i--) {
    let j = Math.floor(Math.random() * (i + 1));
    [keys[i], keys[j]] = [keys[j], keys[i]];
}

let output = '';

for (let i = 0; i < keys.length; i++) {
    let time = keys[i];
    let price = generatePrice(i + 1);
    let name = generateName(i + 1);

    output += `${time}\n${price}\n${name}\n\n`;
}

fs.writeFileSync('../tasks.txt', output, 'utf8');
