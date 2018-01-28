const assert = require('assert');
const math = require('../index');

describe('Algorithms', function() {
    describe('#div', function() {
        it('should divides numbers and returns answer with demanded precision', function() {
            let a = 2.3;
            let b = 7;            
            assert.equal(0.32857142857142857, math.div(a, b,17));
            assert.equal(0.32857142, math.div(a, b,8));
            assert.equal(0.32857, math.div(a, b,5));
            assert.equal(0.32, math.div(a, b,2));
        });
    });
});