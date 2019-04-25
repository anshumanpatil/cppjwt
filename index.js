const jwtAddon = require('./build/Release/jwtAddon.node');
console.log(jwtAddon);
let token = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiaWF0IjoxNTE2MjM5MDIyfQ.SflKxwRJSMeKKF2QT4fwpMeJf36POk6yJV_adQssw5c";
let str = jwtAddon.jwtcpp(token);
console.log('hello ', JSON.parse(str)["name"]);