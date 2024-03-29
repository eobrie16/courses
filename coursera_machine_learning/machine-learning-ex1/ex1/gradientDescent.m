function [theta, J_history] = gradientDescent(X, y, theta, alpha, num_iters)
%GRADIENTDESCENT Performs gradient descent to learn theta
%   theta = GRADIENTDESCENT(X, y, theta, alpha, num_iters) updates theta by
%   taking num_iters gradient steps with learning rate alpha

% Initialize some useful values
m = length(y); % number of training examples
J_history = zeros(num_iters, 1);

for iter = 1:num_iters

    % ====================== YOUR CODE HERE ======================
    % Instructions: Perform a single gradient step on the parameter vector
    %               theta.
    %
    % Hint: While debugging, it can be useful to print out the values
    %       of the cost function (computeCost) and gradient here.
    %
    x = X(:,2);
    temp0 = theta(1) - alpha*sum(theta(1)+theta(2)*x-y)/(m);
    temp1 = theta(2) - alpha*sum((theta(1)+theta(2)*x-y).*x)/(m);
    theta(1) = temp0;
    theta(2) = temp1;
    % ============================================================

    % Save the cost J in every iteration
    disp("cost= "), disp(computeCost(X, y, theta));
    J_history(iter) = computeCost(X, y, theta);
    if (iter > 1)
      if (J_history(iter) > J_history(iter-1));
        break;
      endif
    endif

end

end
