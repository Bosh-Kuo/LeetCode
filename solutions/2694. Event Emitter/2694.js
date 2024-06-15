class EventEmitter {
  /**
   * @param {string} eventName
   * @param {Function} callback
   * @return {Object}
   */

  constructor() {
    this.events = [];
  }

  subscribe(eventName, callback) {
    this.events.push({ [eventName]: callback });
    return {
      unsubscribe: () => {
        const indexDelete = this.events.findIndex(
          (event) => Object.keys(event)[0] === eventName
        );
        if (indexDelete !== -1) {
          this.events.splice(indexDelete, 1);
        }
      },
    };
  }

  /**
   * @param {string} eventName
   * @param {Array} args
   * @return {Array}
   */
  emit(eventName, args = []) {
    const emitEvents = this.events.filter((event) =>
      event.hasOwnProperty(eventName)
    );
    const results = [];

    emitEvents.forEach((event) => {
      const callback = event[eventName];
      if (typeof callback === "function") {
        results.push(callback(...args));
      }
    });

    return results;
  }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */
