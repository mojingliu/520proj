public String printInfo(int width, int height, int appleX, int appleY)
    {
        SnakeHead head = this;
        int direction = head.getFacing();
        int diffX = head.getX() - appleX;
        int diffY = head.getY() - appleY;  // positive: head is below apple
        int newDiffX, newDiffY;
        String toR = "";
        SnakeBody sn;
        switch(direction)
        {
            case 1: // up
                if(diffY > 0 && Math.abs(diffY) > Math.abs(diffX))
                {
                    if(diffX == 0)
                        toR += "You see an apple " + Math.abs(diffY) + " feet straight ahead!";
                    else if(diffX < 0)
                        toR += "You see an apple " + Math.abs(diffY) + " feet ahead and to your right!";
                    else
                        toR += "You see an apple " + Math.abs(diffY) + " ahead and to your left!";
                }
                sn = head;
                for(;sn != null; sn = sn.rest)
                {
                    newDiffX = head.getX() - sn.getX();
                    newDiffY = head.getY() - sn.getY();
                    if(newDiffX == 0 && newDiffY > 0)
                        toR += "You see your own body " + newDiffY + " feet in front of you!";
                }
                if(toR == "")
                    toR = "There's a wall " + head.getY()+1 + " feet in front of you.";
                return toR;
            case 2: // right ======================================================
                if(diffX < 0 && Math.abs(diffX) > Math.abs(diffY))
                {
                    if(diffY == 0)
                        toR += "You see an apple " + Math.abs(diffX) + " feet straight ahead!";
                    else if(diffX < 0)
                        toR += "You see an apple " + Math.abs(diffX) + " feet ahead and to your right!";
                    else
                        toR += "You see an apple " + Math.abs(diffX) + " ahead and to your left!";
                }
                sn = head;
                for(;sn != null; sn = sn.rest)
                {
                    newDiffX = head.getX() - sn.getX();
                    newDiffY = head.getY() - sn.getY();
                    if(newDiffY == 0 && newDiffX < 0)
                        toR += "You see your own body " + newDiffY + " feet in front of you!";
                }
                if(toR == "")
                    toR = "There's a wall " + (width-head.getX())+1 + " feet in front of you.";
                return toR;
            case 4: // down =======================================================
                if(diffY < 0 && Math.abs(diffY) > Math.abs(diffX))
                {
                    if(diffX == 0)
                        toR += "You see an apple " + Math.abs(diffY) + " feet straight ahead!";
                    else if(diffX < 0)
                        toR += "You see an apple " + Math.abs(diffY) + " feet ahead and to your left!";
                    else
                        toR += "You see an apple " + Math.abs(diffY) + " ahead and to your right!";
                }
                sn = head;
                for(;sn != null; sn = sn.rest)
                {
                    newDiffX = head.getX() - sn.getX();
                    newDiffY = head.getY() - sn.getY();
                    if(newDiffX == 0 && newDiffY < 0)
                        toR += "You see your own body " + newDiffY + " feet in front of you!";
                }
                if(toR == "")
                    toR = "There's a wall " + height - head.getY()+1 + " feet in front of you.";
                return toR;
            case 8: // left
                if(diffX > 0 && Math.abs(diffX) > Math.abs(diffY))
                {
                    if(diffY == 0)
                        toR += "You see an apple " + Math.abs(diffX) + " feet straight ahead!";
                    else if(diffX < 0)
                        toR += "You see an apple " + Math.abs(diffX) + " feet ahead and to your left!";
                    else
                        toR += "You see an apple " + Math.abs(diffX) + " ahead and to your right!";
                }
                sn = head;
                for(;sn != null; sn = sn.rest)
                {
                    newDiffX = head.getX() - sn.getX();
                    newDiffY = head.getY() - sn.getY();
                    if(newDiffY == 0 && newDiffX > 0)
                        toR += "You see your own body " + newDiffY + " feet in front of you!";
                }
                if(toR == "")
                    toR = "There's a wall " + (head.getX()+1) + " feet in front of you.";
                return toR;
        }
        return "";
    }