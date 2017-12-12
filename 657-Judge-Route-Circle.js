/**
 * @param {string} moves
 * @return {boolean}
 */
const judgeCircle = function (moves) {
    return (
        moves.split("L").length == moves.split("R").length 
        && moves.split("U").length == moves.split("D").length
    )
}

const judgeCircle = function (moves) {
    let x = 0
    let y = 0
    for (let i = 0, l = moves.length; i < l; i++) {
        const move = moves[i]
        switch (move) {
            case 'U': y--
                break
            case 'D': y++
                break
            case 'L': x--
                break
            case 'R': x++
                break
        }
    }
    return x === 0 && y === 0
}