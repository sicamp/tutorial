var n, m, i, j: integer;
    a: array [0..101, 0..101] of integer;
    fail: boolean;
begin
    assign(input, 'carrots.in');
    assign(output, 'carrots.out');
    reset(input);
    rewrite(output);

    read(n, m);
    for i := 1 to n do
        for j := 1 to m do
            read(a[i, j]);

    fail := false;
    for i := 1 to n do
        for j := 1 to m do
            if a[i, j] = 1 then
                if (a[i - 1, j - 1] = 1) or (a[i - 1, j + 1] = 1) then
                    fail := true;
    
    if fail then
        writeln('NO')
    else
        writeln('YES');

    close(input);
    close(output);
end.
