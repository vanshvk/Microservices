import { initializePuppeteerWeb } from './initialize-web.js';
import { isNode } from './environment.js';

if (isNode) {
  throw new Error('Trying to run Puppeteer-Web in a Node environment');
}

export default initializePuppeteerWeb('puppeteer');
