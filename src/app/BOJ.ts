import { Builder, By, until } from 'selenium-webdriver';
import type { ThenableWebDriver } from 'selenium-webdriver';
import { Options } from 'selenium-webdriver/chrome';

export class BOJ {
  private driver: ThenableWebDriver;

  constructor() {
    this.driver = new Builder()
      .forBrowser('chrome')
      .setChromeOptions(
        new Options().addArguments(
          '--headless',
          '--no-sandbox',
          '--single-process',
          '--disable-dev-shm-usage'
        )
      )
      .build();
  }

  public async exit() {
    await this.driver.quit();
  }

  public async login(id: string, password: string) {
    try {
      await this.driver.get('https://www.acmicpc.net/login');
      await this.driver.findElement(By.name('login_user_id')).sendKeys(id);
      await this.driver.findElement(By.name('login_password')).sendKeys(password);
      await this.driver.findElement(By.name('auto_login')).click();
      await this.driver.findElement(By.id('submit_button')).click();
      await this.driver.wait(until.titleIs('Baekjoon Online Judge'), 2000);

      return (await this.driver.manage().getCookie('bojautologin')).value;
    }
    catch (err) {
      return '';
    }
  }
}
