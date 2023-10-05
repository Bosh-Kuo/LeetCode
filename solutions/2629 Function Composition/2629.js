/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function (functions) {
  return function (x) {
    let val = x;
    const length = functions.length;
    for (let i = 0; i < length; i++) {
      val = functions.pop()(val);
    }
    return val;
  };
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
