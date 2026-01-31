function handleGenerate() {
    const inputArea = document.getElementById('inputArea');
    const source = inputArea.value;

    if (!source.trim()) return alert("Please paste your code first!");

    // 1. Clean first
    let result = Engine.stripComments(source);

    // 2. SAFETY FIRST: Hide Headers AND Literals
    result = Engine.maskHeaders(result);   // <--- New Step
    result = Engine.maskLiterals(result);

    // 3. Process Code (Safe now)
    result = Engine.applyVariableMapping(result);
    result = Engine.swapLogic(result);
    
    // 4. Unmask Everything
    result = Engine.unmaskLiterals(result);
    result = Engine.unmaskHeaders(result);

    // 5. Inject New Macros (After unmasking, so we can replace old includes)
    result = Engine.injectMacros(result);

    // 6. Calc Stats & Render
    const diffPercent = Engine.calculateDiff(source, result);
    updateBadge(diffPercent);

    const outputDiv = document.getElementById('outputArea');
    let safeHTML = escapeHtml(result);
    safeHTML = safeHTML.replace(/§§(.*?)§§/g, '<span class="diff-new">$1</span>');

    outputDiv.innerHTML = safeHTML;
    outputDiv.style.display = 'block';
}

// ... keep existing copyToClipboard, escapeHtml, and updateBadge functions ...
function copyToClipboard() {
    const outputDiv = document.getElementById('outputArea');
    const cleanText = outputDiv.innerText;
    if (!cleanText) return;
    navigator.clipboard.writeText(cleanText).then(() => {
        alert("Clean code copied!");
    });
}

function updateBadge(percent) {
    const badge = document.getElementById('diffBadge');
    badge.innerText = `Dissimilarity: ${percent}%`;
    badge.style.display = 'block';
    if (percent >= 30) badge.classList.add('high-diff');
    else badge.classList.remove('high-diff');
}

function escapeHtml(text) {
    return text.replace(/&/g, "&amp;").replace(/</g, "&lt;").replace(/>/g, "&gt;").replace(/"/g, "&quot;").replace(/'/g, "&#039;");
}