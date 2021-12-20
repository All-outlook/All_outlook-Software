 int line_step(int line){ 
    if (line_reaction == 0) {
      line_reaction = 1;

      if (line != 0) {
        line_count = goal_count(line_time);
      } else if (line == 0) {
        line_count = -1;
      }
    } else if (line_reaction == 1) {
    }

    if (line == 0) {
      line_reaction = 0;
    }

    if (period_count == line_count) {
      line_reaction = 0;
      line = 0;
    }
    return line;
  }
