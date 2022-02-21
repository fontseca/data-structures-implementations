function entries() {
  const res = new Array(0);
  let head = this.head;

  for (let i = 0; i < this.size; ++i) {
    res[i] = head.data;
    head = head.next;
  }
  
  return res;
}

module.exports = entries;