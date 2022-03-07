function BinarySearchTree() {
  let root = null;

  function Stack() {
    function StackNode(data = {}) {
      this.next = null;
      this.data = data;
    }
  
    let placeolder = new StackNode();
  
    this.push = function push(data) {
      let newNode = new StackNode(data);
      newNode.next = placeolder.next;
      placeolder.next = newNode;
    }
  
    this.pop = function pop() {
      if (this.isEmpty()) throw Error('stack underflow');
      let tmpNode = placeolder.next;
      placeolder.next = tmpNode.next;
      return tmpNode.data;
    }
  
    this.peek = function peek() {
      if (this.isEmpty()) throw Error('stack underflow');
      return placeolder.next.data;
    }
  
    this.entries = function entries() {
      if (this.isEmpty()) throw Error('stack is empty');
      let tmp = placeolder.next;
      let set = new Set();
      while (tmp !== null) {
        set.add(tmp.data.key);
        tmp = tmp.next;
      }

      return set;
    }

    this.destroy = function destroy() {
      placeolder.next = null;
      return true;
    }

    this.isEmpty = function isEmpty() {
      return placeolder.next === null;
    }
  
  }

  function TreeNode(key = null, data = {}) {
    this.data = data;
    this.key = key;
    this.left = null;
    this.right = null;
    this.parent = null;
  }
  
  this.insert = function insert(key, data) {
    let y = null;
    let x = root;
    let z = new TreeNode(key, data);

    while (x !== null) {
      y = x;
      x = (z.key < x.key) ? x.left : x.right;
    }
    z.parent = y;
    if (y == null)
      root = z; /* tree was empty */
    else if (z.key < y.key)
      y.left = z;
    else
      y.right = z;
  }

  this.minimun = function minimun(x = root) {
    if (x.left !== null)
      return minimun(x.left);
    return x;
  }

  this.maximun = function maximun(x = root) {
    if (x.right !== null)
      return maximun(x.right);
    return x;
  }

  this.inorderTraversal = function inorderTraversal() {
    let min = this.minimun();
    let x = this.maximun();
    let st = new Stack();

    while (x !== null) {
      if (x.left === null && x.right === null) {
        st.push(x);
        if (x.key === min.key) break;
        x = x.parent;
        continue;
      }

      if (x.left !== null && x.right !== null) {
        if (st.peek().key < x.key) {
          x = x.parent;
          continue;
        }

        if (x.right.key >= st.peek().key) {
          st.push(x);
          x = x.left;
          continue;
        }

        x = x.right;
        continue;
      }

      if (x.left === null && x.right !== null) {
        if (x.right.key >= st.peek().key) {
          st.push(x);
          if(x.key === min.key) break;
          x = x.parent;
          continue;
        } else {
          x = x.right;
          continue;
        }
        
      }

      if (x.left !== null && x.right === null) {
        st.push(x);
        x = x.left;
        continue;
      }

    }

    let entries = st.entries();
    st.destroy();
    return entries;
  }

}
console.clear();

var tr = new BinarySearchTree();

tr.insert(10, {});
tr.insert(15, {});
tr.insert(20, {});
tr.insert(25, {});
tr.insert(30, {});
tr.insert(11, {});
tr.insert(12, {});
tr.insert(17, {});
tr.insert(18, {});
tr.insert(16, {});
tr.insert(7, {});
tr.insert(9, {});
tr.insert(3, {});
tr.insert(4, {});
tr.insert(5, {});
tr.insert(2, {});
tr.insert(1, {});

console.log(tr.inorderTraversal()); // Set(17) { 1, 2, 3, 4, 5, 7, 9, 10, 11, 12, 15, 16, 17, 18, 20, 25, 30 }