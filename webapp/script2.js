const password = document.getElementById('password');
const passwordAgain = document.getElementById('passwordAgain');

password.addEventListener('blur', ()=>{
   if (password.value.length !== 8){
       password.setCustomValidity("Password must be 8 characters length");
       password.reportValidity();
   }
});

passwordAgain.addEventListener('blur', ()=>{
   if (password.value !== passwordAgain.value)
       passwordAgain.setCustomValidity('Passwords do not match');
   passwordAgain.reportValidity();
});

password.addEventListener('keydown', ()=>password.setCustomValidity(''));

passwordAgain.addEventListener('keydown', ()=>passwordAgain.setCustomValidity(''));
