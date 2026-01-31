// script.js
function handleGenerate() {
    const inputArea = document.getElementById('inputArea');
    const source = inputArea.value;

    if (!source.trim()) return;

    let result = Engine.stripComments(source);
    result = Engine.applyVariableMapping(result); // Meaningful names
    result = Engine.implementMacros(result);      // Deep macro usage
    result = Engine.injectMacros(result);         // Header injection

    const diffPercent = Engine.calculateDiff(source, result);
    
    const outputDiv = document.getElementById('outputArea');
    outputDiv.innerText = result;
    outputDiv.style.display = 'block';

    const badge = document.getElementById('diffBadge');
    badge.innerText = `Dissimilarity: ${diffPercent}%`;
    badge.style.display = 'block';
    if (diffPercent >= 30) badge.classList.add('high-diff');
}