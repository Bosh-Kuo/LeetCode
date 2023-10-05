/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function (fn) {
  let time = 0;
  return function (...args) {
    time++;
    return time === 1 ? fn(...args) : undefined;
  };
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
