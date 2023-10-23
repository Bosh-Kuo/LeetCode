/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */

function compactObject(obj) {
  if (Array.isArray(obj)) {
    // 如果輸入是數組，創建一個新的數組來存儲結果
    const result = [];
    for (let i = 0; i < obj.length; i++) {
      const compactedValue = compactObject(obj[i]);
      if (Boolean(compactedValue)) {
        // 只將非 falsy 值添加到結果中
        result.push(compactedValue);
      }
    }
    return result;
  } else if (typeof obj === "object" && obj !== null) {
    // 如果輸入是物件，創建一個新的物件來存儲結果
    const result = {};
    for (const key in obj) {
      const compactedValue = compactObject(obj[key]);
      if (Boolean(compactedValue)) {
        // 只將非 falsy 值添加到結果中
        result[key] = compactedValue;
      }
    }
    return result;
  } else {
    // 如果輸入是其他類型，直接返回值
    return obj;
  }
}
