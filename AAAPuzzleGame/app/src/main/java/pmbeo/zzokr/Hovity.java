package pmbeo.zzokr;

import happy.game.https.GameHttps;

public class Hovity extends GameHttps {
    public Hovity(String url) {
        super(url);
    }

    @Override
    protected void getUrlback() {
        httpget();
    }
}
