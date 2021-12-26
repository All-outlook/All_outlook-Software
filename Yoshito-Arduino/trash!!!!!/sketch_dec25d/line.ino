int line_serial;
int line_step;

int F_line_serial()
{
    if(line_serial.available() > 0)
    line_serial = line_serial.read();
} else {
    line_serial = 0;
} 
    return line_serial;
}

int F_line_avoid(int line)
{
    if (0 <= line < line <= 32)
    {
        line_step = line * 11.25;
    }
    else
    {
        line_step = 0;
    }
    return line_step;
}
