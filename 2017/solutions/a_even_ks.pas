var n, i, even, odd: longint;
    a: array [1..100000] of longint;
begin
    assign(input, 'even.in');
    assign(output, 'even.out');
    reset(input);
    rewrite(output);

    read(n);
    for i := 1 to n do
        read(a[i]);

    even := 0;
    odd := 0;
    for i := 1 to n do
        if a[i] mod 2 = 0 then
            inc(even)
        else
            inc(odd);
    
    writeln(even);
    for i := 1 to n do
        if a[i] mod 2 = 0 then
            write(a[i], ' ');
    writeln;

    writeln(odd);
    for i := 1 to n do
        if a[i] mod 2 = 1 then
            write(a[i], ' ');
    writeln;

    close(input);
    close(output);
end.
