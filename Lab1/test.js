function length(s) {
    console.log("Function evaluated");

    let len = 0;
    while (s[len] !== undefined) {
        len++;
    }

    return len;
}

function main() {
    const s = "BizzCom";

    for (let i = 0; i < length(s) - 1; i++) {
        console.log("Loop ran " + i);
    }
}
main()