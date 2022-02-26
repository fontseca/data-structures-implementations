function Stack() {
  function StackNode(data = null) {
    this.data = data;
    this.next = null;
  }

  let _placeholder = new StackNode();
  let _size  = 0;

  this.push = function push(data) {
    let newNode = new StackNode(data);
    newNode.next = _placeholder.next;
    _placeholder.next = newNode;
    _size++;
  }

  this.pop = function pop() {
    if (this.empty()) throw Error('stack underflow');
    let tmpNode = _placeholder.next;
    let tmpData = tmpNode.data;
    _placeholder.next = tmpNode.next;
    tmpNode = null;
    _size--;
    return tmpData;
  }

  this.peek = function peek() {
    if (this.empty()) throw Error('stack underflow');
    return _placeholder.next.data;
  }

  this.empty = function empty() {
    return _placeholder.next === null;
  }

  this.size = function size() {
    return _size;
  }

  this.destroy = function destroy() {
    _placeholder.next = null;
  }
}

/**
 * @param {string} exp
 */
function infixToReversePolishNotation(exp) {
  let res = '';
  let st = new Stack();

  for (let i = 0; i < exp.length; ++i) {
    if (isOperand(exp[i])) {
      res += exp[i];
    } else if (isOperator(exp[i])) {
      while (!st.empty() && !isOpening(exp[i]) && higherPrecedence(st.peek(), exp[i])) {
        res += st.pop();
      }
      st.push(exp[i]);
    } else if (isOpening(exp[i])) {
      st.push(exp[i]);
    } else if (isClosing(exp[i])) {
      while (!st.empty() && !isOpening(st.peek())) {
        res += st.pop();
      }
      
      st.pop();
    }
  }

  while (!st.empty()) {
    res += st.pop();
  }

  return res;
}

function higherPrecedence(op1 = '', op2 = '') {
  switch (op1) {
    case '^': return op2 == '^' ? false : true;
    case '+': case '-':
      if (op2 == '*' || op2 == '/') return false;
      else break;
    case '*': case '/':
      if (op2 == '+' || op2 == '-') return true;
      else break;
    default: return false;
  }
  return false;
}

function isClosing(c = '') {
  return c == ')' || c == '}' || c == ']';
} 

function isOpening(c = '') {
  return c == '(' || c == '{' || c == '[';
} 

function isOperand  (c = '') {
  let code = c.charCodeAt(0);
  return (code >= 65 && code <= 90) || (code >= 97 && code <= 122) || (code >= 48 && code <= 57);
}

function isOperator(c = '') {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

console.clear();
const exp = '(a+b)*(b+c)';
const res = infixToReversePolishNotation(exp);
console.log(res); // ab+bc+*