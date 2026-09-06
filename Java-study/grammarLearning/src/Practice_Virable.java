public class Practice_Virable {
    static void main() {
        double ourATK = 220;
        double ourDefence = 85;
        double outHP = 1012.5;
        double ourSkill = 1.2;
        double enemyATK = 210;
        double enemyDefence = 80;
        double enemyHP = 1223.3;
        double enemySkill = 1.3;
        double ourHit = ourATK-enemyDefence;
        double ourSkillHit = ourATK * ourSkill -enemyDefence;
        System.out.println("第一次普通攻击对方剩余"+(enemyHP-ourHit)+"滴血");
        enemyHP-=ourHit;
        System.out.println("第二次技能攻击对方剩余"+(enemyHP-ourSkillHit)+"滴血");
        enemyHP-=ourSkillHit;

    }
}
