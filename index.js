const jwtAddon = require('./build/Release/jwtAddon.node');
console.log('hello ', jwtAddon.jwtcpp("Anshuman.patil"));
module.exports = jwtAddon;