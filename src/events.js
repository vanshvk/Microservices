(async () => {
  const browser = await puppeteer.launch();
  const page = await browser.newPage();

  // Define a window.onCustomEvent function on the page.
  await page.exposeFunction('onCustomEvent', (e) => {
    console.log(`${e.type} fired`, e.detail || '');
  });

  /**
   * Attach an event listener to page to capture a custom event on page load/navigation.
   * @param {string} type Event name.
   * @returns {!Promise}
   */
  function listenFor(type) {
    return page.evaluateOnNewDocument((type) => {
      document.addEventListener(type, (e) => {
        window.onCustomEvent({ type, detail: e.detail });
      });
    }, type);
  }

  await listenFor('app-ready'); // Listen for "app-ready" custom event on page load.

  await page.goto('https://www.chromestatus.com/features', {
    waitUntil: 'networkidle0',
  });

  await browser.close();
})();
