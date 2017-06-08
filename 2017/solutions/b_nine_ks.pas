{$H+}
var a, b: string;

function dsum(s : string) : longint;
var i: longint;
begin
    dsum := 0;
    for i := 1 to length(s) do
        dsum := dsum + ord(s[i]) - ord('0');
end;

begin
    assign(input, 'nine.in');
    assign(output, 'nine.out');
    reset(input);
    rewrite(output);

    readln(a);
    readln(b);

    if Int64(dsum(a)) * dsum(b) mod 9 = 0 then
        writeln('YES')
    else
        writeln('NO');

    close(input);
    close(output);
end.
