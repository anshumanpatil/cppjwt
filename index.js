const testAddon = require('./build/Release/testaddon.node');
// console.log('addon',testAddon);
// console.log(testAddon.hello());
console.log('hello ', testAddon.jwtcpp("Anshuman"));
// console.log('add ', testAddon.add(5, 10));
module.exports = testAddon;