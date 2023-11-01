const main_p_div = document.getElementById('main-div');
const bg_color_input = document.getElementById('bg-color-input');
const border_color_input = document.getElementById('border-input');

bg_color_input.addEventListener('keydown', ()=>{
    bg_color_input.setCustomValidity('');
});

bg_color_input.addEventListener('blur', (event)=>{
    event.target.setCustomValidity('');
    const value = event.target.value;
    if (value.length !== 6){
        event.target.setCustomValidity('Input valid hex values');
        bg_color_input.reportValidity();
        event.stopPropagation();
        return;
    }
    main_p_div.style.color = `#${value}`;
});

border_color_input.addEventListener('blur', (event)=>{
    main_p_div.style.borderWidth = `${event.target.value}px`;
});

