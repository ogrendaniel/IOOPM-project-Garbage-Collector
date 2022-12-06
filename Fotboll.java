
public class Fotboll {
    int goals = 0;
    int goalsAgainst = 0;
    int wins = 0;
    int draws = 0;
    int losses = 0;
    int points = 0;
    String soutKorea = "SOUTH KOREA";
    String spain = "Spain";
    String brazil = "Brazil";
    public Fotboll(int goals, int goalsAgainst, int wins, int draws, int losses, int points) {
        this.goals = goals;
        this.goalsAgainst = goalsAgainst;
        this.wins = wins;
        this.draws = draws;
        this.losses = losses;
        this.points = points;
    }

    public int getGoals() {
        return goals;
    }

    public void setGoals(int goals) {
        this.goals = goals;
    }

    public int getGoalsAgainst() {
        return goalsAgainst;
    }

    public void setGoalsAgainst(int goalsAgainst) {
        this.goalsAgainst = goalsAgainst;
    }

    public int getWins() {
        return wins;
    }

    public void setWins(int wins) {
        this.wins = wins;
    }

    public int getDraws() {
        return draws;
    }

    public void setDraws(int draws) {
        this.draws = draws;
    }

    public int getLosses() {
        return losses;
    }

    public void setLosses(int losses) {
        this.losses = losses;
    }

    public int getPoints() {
        return points;
    }

    public void setPoints(int points) {
        this.points = points;
    }

    



    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println("Hello football lovers");
    }
    

}
