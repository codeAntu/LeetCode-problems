type Func = (x: number) => number;

function compose(functions: Func[]): Func {
  return function (x: number): number {
    return functions.reverse().reduce((acc, fn) => fn(acc), x);
  };
}
