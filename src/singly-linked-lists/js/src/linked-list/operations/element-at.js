const { outOfRange: { greater, lower} } = require('../errors/errs.js');

function elementAt(position = 0) {
  if (position >= this.size) throw new Error(greater);
  if (position < 0) throw new Error(lower);
  
  let currentNode = this.head;
  for (let i = 0; i < position; ++i)
    currentNode = currentNode.next;
  return currentNode.data;
}

module.exports = elementAt;