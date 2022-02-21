const LinkedList = require('./src/linked-list/LinkedList.js');
const list = new LinkedList();

list.insertAtEnd('jeremy');
list.insertAtEnd('alexander');
list.insertAtEnd('fonseca');
list.insertAtEnd('blanco');

console.log(list.entries());     // [ 'jeremy', 'alexander', 'fonseca', 'blanco' ]
console.log(list.size);          // 4
console.log(list.elementAt(2));  // 'fonseca'
console.log(list.reverse());     // true
console.log(list.entries());     // [ 'blanco', 'fonseca', 'alexander', 'jeremy' ]
