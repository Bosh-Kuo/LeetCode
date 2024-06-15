/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function (fn) {
  output = {};
  this.forEach((element) => {
    if (fn(element) in output) output[fn(element)].push(element);
    else output[fn(element)] = [element];
  });
  return output;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */
